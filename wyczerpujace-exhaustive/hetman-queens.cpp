
// [PL] problem n hetmanow
// [EN] n queens problem

#include <climits>
#include <stdlib.h>
#include <iostream>
#include <iomanip>      



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
		std::cout << "[PL] Program do rozwiazywania problemu n hetmanow" << std::endl << std::endl;
		std::cout << "     uruchomienie programu: " << std::endl << argumenty[0] << " n" << std::endl;
		std::cout << "     gdzie n to rozmiar szachownicy (liczba kolumn)" << std::endl;
		std::cout << "[EN] Program for n queens problem" << std::endl << std::endl;
		std::cout << "     to run the program: " << std::endl << argumenty[0] << " n" << std::endl;
		std::cout << "     where n is the number of files/columns or ranks/rows of the checkboard" << std::endl;

		return 0;
	} 

	const int N = atoi(argumenty[1]);
	int ustawienie = 0;

	int * wiersze = new int[N];
	int i;
	for (i = 0; i < N; i++)
		wiersze[i] = -1;

	int indeks = 0;

	// [PL] rozpoczynamy od zerowego wiersza
	// [EN] we start with the 0-th row (rank)
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
			// [PL] sprawdzenie, czy ten hetman moze tutaj stac
			// [EN] check if it is legal to locate a queen here
			int poprzedni;
			bool tutaj_moze = true;  

			for (poprzedni = indeks - 1; poprzedni >= 0; poprzedni--)
			{
				// sprawdzenie kolumny
				if (wiersze[indeks] == wiersze[poprzedni]) // nie moze tutaj stac
					tutaj_moze = false;
				else 
				{
					// [PL] sprawdzenie przekatnych
					// [EN] diagonal check
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
				if (indeks == N - 1)  // [PL] postawiony ostatni hetman \ [EN] the last queen
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
