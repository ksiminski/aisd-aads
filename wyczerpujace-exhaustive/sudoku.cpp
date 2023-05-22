
#include <string>
#include <fstream>
#include <iostream>

 


const int MAX = 9;

struct tablica 
{
	char el[MAX][MAX];
	bool orig[MAX][MAX];

	friend std::ostream & operator<< (std::ostream & s, tablica & t);
};

std::ostream & operator<< (std::ostream & s, tablica & t)
{
	int i, j;
	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			s << t.el[i][j];
		}
		s << std::endl;
	}
	return s;
}

class sudoku
{
	class walidador
	{
		bool el[MAX];
		int liczba_elementow;
		public:
		walidador();
		void reset();
		void add(char);
		bool validate();
	};
	tablica tab;
	bool rozwiaz(int w, int k, tablica tab);
	bool walidacja (tablica & t);
	public:
	std::string plikWyjsciowy;
	void wczytaj(const std::string & plik);
	void zapiszRozwiazanie (const std::string & plik);
	bool rozwiaz();

};

void help (const std::string & nazwa)
{
	std::cout << "Program do rozwiazywania sudoku" << std::endl;
	std::cout << "uruchomienie:" << std::endl;
	std::cout << nazwa << " wejscie wyjscie" << std::endl;

	return;
}

int main(int argc, char * argv[])
{
	if (argc < 3)
	{
		help (argv[0]);
		return 0;
	}

	std::string wejscie (argv[1]);
	std::string wyjscie (argv[2]);
	sudoku s;
	s.wczytaj(wejscie);
	s.rozwiaz();
	s.zapiszRozwiazanie(wyjscie);

	return 0;
}

bool sudoku::walidacja(tablica & t)
{
	int w, k;

	// sprawdzenie wierszy
	for (w = 0; w < MAX; w++)
	{
		walidador wal;
		for (k = 0; k < MAX; k++)
			wal.add(t.el[w][k]);
		if (wal.validate() == false)
			return false;
	}

	// sprawdzenie kolumn
	for (k = 0; k < MAX; k++)
	{
		walidador wal;
		for (w = 0; w < MAX; w++)
			wal.add(t.el[w][k]);
		if (wal.validate() == false)
			return false;
	}

	// sprawdzenie malych kwadratow

	int wq, kq;

	for (wq = 0; wq < MAX / 3; wq++)
	{
		for (kq = 0; kq < MAX / 3; kq++)
		{
			walidador wal;
			for (w = 0; w < MAX / 3; w++)
			{

				for (k = 0; k < MAX / 3; k++)
				{
					wal.add(t.el[wq * 3 + w][kq * 3 + k]);
				}
			}
			if (wal.validate() == false)
				return false;
		}
	}
	return true;
}
sudoku::walidador::walidador()
{
	liczba_elementow = 0;
	reset();
}
bool sudoku::walidador::validate()
{
	int i;
	int licznik = 0;
	for (i = 0 ; i < MAX; i ++)
		if (el[i])
			licznik++;
	return (licznik == liczba_elementow);
}
void sudoku::walidador::reset()
{
	int i;
	for (i = 0; i < MAX; i++)
		el[i] = false;
}
void sudoku::walidador::add(char c)
{
	if (c != '0')
	{
		el[c - '1'] = true;
		liczba_elementow++;
	}
}

bool sudoku::rozwiaz(int w, int k, tablica t)
{
	// usiluje wstawic w miejsce [w][k] kolejne wartosci:

	if (t.orig[w][k] == false) // nie ma danej oryginalnej
	{
		for (char c = '1'; c <= '9'; c++)
		{
			t.el[w][k] = c;
			if (walidacja(t))
			{
				if (w == MAX - 1 && k == MAX - 1)
				{
					// cout << t << std::endl;
					tab = t;
					return true;
				}

				if (w <= MAX)
				{
					if (k < MAX - 1)
					{
						if (rozwiaz(w, k + 1, t))
							return true;
					}
					else
					{
						if (rozwiaz(w + 1, 0, t))
							return true;
					}
				}
			}
		}
	}
	else // jest dana oryginalna, wiec przesuwam sie dalej
	{
		if (w == MAX - 1 && k == MAX - 1)
		{
			// cout << t << std::endl;
			tab = t;
			return true;
		}
		if (w <= MAX)
		{
			if (k < MAX - 1)
			{
				if (rozwiaz(w, k + 1, t))
					return true;

			}
			else
			{
				if (rozwiaz(w + 1, 0, t))
					return true;

			}
		}
	}


	return false;
}

bool sudoku::rozwiaz()
{

	if (rozwiaz(0, 0, tab))
		return true;
	else
		return false;
}

void sudoku::zapiszRozwiazanie(const std::string & s)
{
	std::ofstream plik(s.c_str());

	if (plik)
	{
		int i, j;
		for (i = 0; i < MAX; i++)
		{
			for (j = 0; j < MAX; j++)
			{
				plik << tab.el[i][j];
			}
			plik << std::endl;
		}

		plik.close();
	}
}

void sudoku::wczytaj(const std::string & s)
{
	std::ifstream plik (s.c_str());

	if (plik)
	{
		int i, j;
		for (i = 0; i < MAX; i++)
		{
			std::string linia;
			getline(plik, linia);

			if (linia.length() >= MAX)
			{
				for (j = 0; j < MAX; j++)
				{
					tab.el[i][j] = linia[j];
					if (tab.el[i][j] != '0')
						tab.orig[i][j] = true;
					else
						tab.orig[i][j] = false;

				}
			}

		}
		plik.close();
	}


}
