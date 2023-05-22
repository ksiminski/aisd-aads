
/* Program wypisuje drzewo gry dla kółka i krzyżyka. */


#include <vector>
#include <iostream>
#include <memory>



// Pozycja na planszy
class pozycja
{
	static const int MAX = 3; // rozmiar tablicy

	char plansza [MAX][MAX];

	std::vector<std::shared_ptr<pozycja>> potomki;
	int ocenSytuacje(const char symbol);
	std::shared_ptr<pozycja> kopiuj ();
	int ocena;
	
  public:
	static int numer;

	static const char KRZYZYK = 'X';
	static const char KOLKO = 'O';
	static const char PUSTA = ' ';
	void inicjalizujPlansze();

	void wstawSymbol (const char symbol);
	void wstawSymbol (const char symbol, int w, int k);
	// ocenia sytuacje ze wzgledu na podany symbol, 
	// gdy symbol wygrywa +1, gdy przegrywa -1, remis 0
	int ocenSytuacjeDlaKrzyzyka();

	void wypisz();
	void wypiszLiscie();

	int ocenSytuacjeMax();
	int ocenSytuacjeMin();
	~pozycja ();

};

int pozycja::numer;

int main(int argc, char * argv[])
{
	pozycja pierwszy;
	pierwszy.inicjalizujPlansze();
	pierwszy.numer = 0;
	// rozpoczynamy od wstawienia krzyzyka
	pierwszy.wstawSymbol(pozycja::KRZYZYK);

	

	pierwszy.wypiszLiscie();
	auto ocena = pierwszy.ocenSytuacjeMax();
	std::cout << "ocena dla gracza rozpoczynajacego: " << ocena << std::endl;
	std::cout << "estimation for starting player:    " << ocena << std::endl;
	

	return 0;
}

void pozycja::wypiszLiscie()
{
	if (potomki.size() == 0)
	{
		std::cout << std::endl << std::endl;
		std::cout << "===" << ++numer << "===" << std::endl << std::endl;

		wypisz();
		return;
	}
	for (auto iter = potomki.begin(); iter != potomki.end(); ++iter)
		(*iter)->wypiszLiscie();
}

void pozycja::wypisz()
{
	int w, k;

	std::cout << "+";
	for (k = 0; k < MAX; k++)
		std::cout << "-+";
	std::cout << std::endl;
	for (w = 0; w < MAX; w++)
	{
		std::cout << "|";
		for (k = 0; k < MAX; k++)
			std::cout << plansza[w][k] << "|";
		std::cout << std::endl;

		std::cout << "+";
		for (k = 0; k < MAX; k++)
			std::cout << "-+";
		std::cout << std::endl;

	}

}

void pozycja::wstawSymbol (const char symbol, int w, int k)
{
	plansza[w][k] = symbol;
}

void pozycja::wstawSymbol (const char symbol)
{
	// najpierw trzeba ocenic sytuacje na planszy,
	// moze juz koniec rozgrywki
	ocena = ocenSytuacjeDlaKrzyzyka();
	if (ocena != 0)
		return; // koniec rozgrywki

	int w, k;
	for (w = 0; w < MAX; w++)
		for (k = 0; k < MAX; k++)
		{
			if (plansza[w][k] == PUSTA)
			{
				auto p = kopiuj();
				p->wstawSymbol(symbol, w, k);
				potomki.push_back(p);
			}
		}

	char symbol_przeciwny = symbol == KRZYZYK ? KOLKO : KRZYZYK;

	for (auto iter = potomki.begin(); iter != potomki.end(); ++iter)
		(*iter)->wstawSymbol(symbol_przeciwny);
}

std::shared_ptr<pozycja> pozycja::kopiuj()
{
	auto temp = std::shared_ptr<pozycja> (new pozycja);
	int w, k;
	for (w = 0; w < MAX; w++)
		for (k = 0; k < MAX; k++)
			temp->plansza[w][k] = plansza[w][k];

	return temp;
}

pozycja::~pozycja ()
{
	 
}

int pozycja::ocenSytuacjeMax()
{
	if (potomki.size() == 0)
		return ocenSytuacjeDlaKrzyzyka();
	else
	{
		int ocena = -10;
		for (auto iter = potomki.begin(); iter != potomki.end(); ++iter)
		{
			int ocena_potomka = (*iter)->ocenSytuacjeMin();
			if (ocena < ocena_potomka)
				ocena = ocena_potomka;

		}
		return ocena;
	}
}

int pozycja::ocenSytuacjeMin()
{
	if (potomki.size() == 0)
		return ocenSytuacjeDlaKrzyzyka();
	else
	{
		int ocena = +10;
		for (auto iter = potomki.begin(); iter != potomki.end(); ++iter)
		{
			int ocena_potomka = (*iter)->ocenSytuacjeMax();
			if (ocena > ocena_potomka)
				ocena = ocena_potomka;

		}
		return ocena;
	}
}


int pozycja::ocenSytuacjeDlaKrzyzyka()
{
	if (ocenSytuacje(KRZYZYK) == 1)
		return 1;
	if (ocenSytuacje(KOLKO) == 1)
		return -1;
	return 0;
}

int pozycja::ocenSytuacje(const char symbol)
{
	int w, k;

	// sprawdzenie dla symbolu podanego
	for (w = 0; w < MAX; w++)
	{
		bool jest_wiersz = true;
		for (k = 0; k < MAX; k++)
		{
			if (plansza[w][k] != symbol)
				jest_wiersz = false;
		}

		if (jest_wiersz)
			return 1; 
	}

	for (k = 0; k < MAX; k++)
	{
		bool jest_kolumna = true;
		for (w = 0; w < MAX; w++)
		{
			if (plansza[w][k] != symbol)
				jest_kolumna = false;
		}

		if (jest_kolumna)
			return 1; 
	}

	// przekatne
	bool jest_przekatna = true;
	for (w = 0; w < MAX; w++)
	{
		if (plansza[w][w] != symbol)
			jest_przekatna = false;
	}
	if (jest_przekatna)
		return 1;

	jest_przekatna = true;
	for (w = 0; w < MAX; w++)
	{
		if (plansza[w][MAX - 1 - w] != symbol)
			jest_przekatna = false;
	}
	if (jest_przekatna)
		return 1;

	return 0;
}
void pozycja::inicjalizujPlansze()
{
	int w, k;
	for (w = 0; w < MAX; w++)
		for (k = 0; k < MAX; k++)
			plansza[w][k] = PUSTA;
}


