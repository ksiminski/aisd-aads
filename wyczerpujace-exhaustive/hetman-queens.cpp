
// Program do rozwiazywania problemu n hetmanow

#include <climits>
#include <stdlib.h>
#include <iostream>
#include <iomanip>      // std::setw

 


#define DEBUG(x) { std::cout << #x << " = " << x << std::endl; }

void wypisz(int * wiersze, int max, int ustawienie)
{
	int w, k;

	std::cout << std::endl << "== " << ustawienie << " ==" << std::endl << std::endl;

	std::cout << "+";
	for (k = 0; k < max; k++)
		std::cout << "-+";
	std::cout << std::endl;
	for (w = 0; w < max; w++)
	{
		std::cout << "|";
		for (k = 0; k < wiersze[w]; k++)
			std::cout << " |";
		std::cout << "H|";
		for (k = wiersze[w] + 1; k < max; k++)
			std::cout << " |";
		std::cout << std::endl;

		std::cout << "+";
		for (k = 0; k < max; k++)
			std::cout << "-+";
		std::cout << std::endl;

	}

}

int main (int ile, char ** argumenty)
{
	if (ile < 2) 
	{
		std::cout << "Program do rozwiazywania problemu n hetmanow" << std::endl << std::endl;
		std::cout << "uruchomienie programu: " << std::endl << argumenty[0] << " n" << std::endl;
		std::cout << "gdzie n to rozmiar szachownicy (liczba kolumn)" << std::endl;

		return 0;
	} 

	const int N = atoi(argumenty[1]);
	int ustawienie = 0;

	int * wiersze = new int[N];
	int i;
	for (i = 0; i < N; i++)
		wiersze[i] = -1;

	int indeks = 0;

	// rozpoczynamy od zerowego wiersza
	while (indeks >= 0)
	{
		wiersze[indeks]++;

		if (wiersze[indeks] == N)
		{
			wiersze[indeks] = -1;
			indeks--;
		}
		else
		{
			// sprawdzenie, czy ten hetman moze tutaj stac
			int poprzedni;
			bool tutaj_moze = true;  

			for (poprzedni = indeks - 1; poprzedni >= 0; poprzedni--)
			{
				// sprawdzenie kolumny
				if (wiersze[indeks] == wiersze[poprzedni]) // nie moze tutaj stac
					tutaj_moze = false;
				else 
				{
					// sprawdzenie przekatnych
					int roznica = indeks - poprzedni;
					if (wiersze[poprzedni] - roznica >= 0)
					{
						if (wiersze[indeks] == wiersze[poprzedni] - roznica) // nie moze tutaj stac
						{
							tutaj_moze = false;
							continue;
						}
					}
					if (wiersze[poprzedni] + roznica < N)
					{
						if (wiersze[indeks] == wiersze[poprzedni] + roznica) // nie moze tutaj stac
						{
							tutaj_moze = false;
							continue;
						}
					}
				}
			}

			if (tutaj_moze)
			{
				if (indeks == N - 1)  // postawiony ostatni hetman
				{  
					wypisz(wiersze, N, ++ustawienie);
				}
				else 
					indeks++;
			}
		}
	}

	delete [] wiersze;

	return 0;
}
