// Program do optymalnego nawiasowania macierzy
// Krzysztof Siminski, 2015

#include <climits>
#include <stdlib.h>
#include <iostream>
#include <iomanip>      // std::setw
#include <vector>


void wypisz(const std::vector<int> & wymiary, const std::vector<std::vector<int>> & indeksy, const int poczatek, const int koniec);

int main (int ile, char ** argumenty)
{
    int liczba_macierzy = ile - 2; 
       
    if (liczba_macierzy < 1) 
    {
        std::cout << "[PL]" << std::endl;
        std::cout << "Program do optymalnego nawiasowania ciagu macierzy." << std::endl << std::endl;
        std::cout << "uruchomienie programu: " << std::endl << argumenty[0] << " r1 r2 rn" << std::endl;
        std::cout << "gdzie r1 r2 rn to ciag rozmiarow macierzy" << std::endl;
        std::cout << "np. dla ciagu macierzy [2 x 5] x [5 x 12] x [12 x 3]" << std::endl;
        std::cout << "nalezy napisac: " << std::endl << argumenty[0] << " 2 5 12 3" << std::endl;       
        std::cout << "Optymalne nawiasowanie jest wypisywane na standardowe wyjscie." << std::endl;
        
        std::cout << "[EN]" << std::endl;
        std::cout << "Program for optimal matrix chain multiplication." << std::endl << std::endl;
        std::cout << "to run a program: " << std::endl << arguments[0] << " r1 r2 rn" << std::endl;
        std::cout << "where r1 r2 rn is a sequence of matrix sizes" << std::endl;
        std::cout << "e.g. for matrix sequence [2 x 5] x [5 x 12] x [12 x 3]" << std::endl;
        std::cout << "type: " << std::endl << arguments[0] << " 2 5 12 3" << std::endl;
        std::cout << "The optimal matrix chain multiplication is printed to the standard output." << std::endl;
        return 0;
    } 
    
    std::vector<int>         wymiary_macierzy    (liczba_macierzy + 1);
    std::vector<std::vector<int>> liczba_mnozen       (liczba_macierzy);
    std::vector<std::vector<int>> indeks_nawiasowania (liczba_macierzy);
            
    int i, j, k;

    // utworzenie tablic pomocniczych (dwuwymiarowych) 
    // Mozna troche zoptymalizowac sposob alokacji tablic,
    // ale tego nie bedziemy robic, dla jasnosci 
    // implementacji.   
    
    for (i = 0; i < liczba_macierzy; i++)
    {
        liczba_mnozen[i]       = std::vector<int> (liczba_macierzy);  
        indeks_nawiasowania[i] = std::vector<int> (liczba_macierzy);  
    }
    
    // odczytanie wymiarow macierzy:

    for (i = 0; i < liczba_macierzy + 1; i++)
        wymiary_macierzy[i] = atoi(argumenty[i + 1]); 
    
    
    // wyznaczenie optymalnego nawiasowania macierzy:
    
    // inicjalizacja tablic:
    for (i = 0; i < liczba_macierzy; i++)
    {
       liczba_mnozen[i][i] = 0; // zerowy koszt
       indeks_nawiasowania[i][i] = i;
       for (j = i + 1; j < liczba_macierzy; j++)
          liczba_mnozen[i][j] = INT_MAX; // duza wartosc
    }
    
    
    // serce programu: wyznaczenie optymalnego nawiasowania
    int temp;
    for (j = 0; j < liczba_macierzy; j++)
    {
       for (i = j - 1; i >= 0; i--)
       {
          for (k = i; k < j; k++)
          {
             temp = liczba_mnozen[i][k] + liczba_mnozen[k + 1][j] + 
                    wymiary_macierzy[i] * 
                    wymiary_macierzy[k + 1] *
                    wymiary_macierzy[j + 1];
             if (temp < liczba_mnozen[i][j])
             {
                liczba_mnozen[i][j] = temp;
                indeks_nawiasowania[i][j] = k;
             } 
          } 
       }
    }
    
    // wypisanie wynikow:
    std::cout << "liczba macierzy | number of matrices:  " << liczba_macierzy << std::endl;
    std::cout << "rozmiary macierzy | sizes of matrices: " << std::endl;
    
    for (i = 0; i < liczba_macierzy; i++)
       std::cout << "A" << i + 1 << ": [" << wymiary_macierzy[i] << " x "
                                     << wymiary_macierzy[i + 1] << "]"
                                     << std::endl;
    std::cout << std::endl;
    
    std::cout << "[PL] LICZBA SCALARNYCH MNOZEN CIAGU MACIERZY A[i..j]:" << std::endl << std::endl;
    std::cout << "[EN] NUMBER OF SCALAR MULTIPLICATIONS IN MATRIX CHAIN A[i..j]:" << std::endl << std::endl;
    for (i = -1; i < liczba_macierzy; i++)
        if (i > -1)
           std::cout << std::setw(10) << i + 1;
        else
        {
           std::cout << std::setw(10) << "i .. j";
           std::cout << '|';
        }
    std::cout << std::endl;
    for (i = -1; i < liczba_macierzy; i++)
       if (i > -1)
          std::cout << std::setw(10) << std::setfill('-') << '-' ;//"----------";
       else
       {
          std::cout << std::setw(10) << std::setfill('-') << '-';
          std::cout << '+';
       }
    std::cout << std::endl; 
    std::cout << std::setfill(' ');   
    
    for (i = 0; i < liczba_macierzy; i++)
    {
        std::cout << std::setw(10) << i + 1 << "|";
        for (j = 0; j < liczba_macierzy; j++)
        {
           if (j < i)
              std::cout << std::setw(10) << ' ';
           else
              std::cout << std::setw(10) << liczba_mnozen[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl << std::endl;
 
    std::cout << "[PL] OPTYMALNE NAWIASOWANIE CIAGU A[i..j] = A[i..k] x A[k + 1 .. j]:" << std::endl << std::endl;
    std::cout << "[EN] OPTIMAL PARENTHESIZATION OF THE CHAIN A[i..j] = A[i..k] x A[k + 1 .. j]:" << std::endl << std::endl;
    for (i = -1; i < liczba_macierzy; i++)
        if (i > -1)
           std::cout << std::setw(10) << i + 1;
        else
        {
           std::cout << std::setw(10) << "i .. j";
           std::cout << '|';
        }
    std::cout << std::endl;
    for (i = -1; i < liczba_macierzy; i++)
       if (i > -1)
          std::cout << std::setw(10) << std::setfill('-') << '-' ;//"----------";
       else
       {
          std::cout << std::setw(10) << std::setfill('-') << '-';
          std::cout << '+';
       }
    std::cout << std::endl; 
    std::cout << std::setfill(' ');   
    
    for (i = 0; i < liczba_macierzy; i++)
    {
        std::cout << std::setw(10) << i + 1 << "|";
        for (j = 0; j < liczba_macierzy; j++)
        {
           if (j < i)
              std::cout << std::setw(10) << ' ';
           else
              std::cout << std::setw(10) << indeks_nawiasowania[i][j] + 1;
        }
        std::cout << std::endl;
    }
 
 
    // wypisanie nawiasowania:
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "[PL] OPTYMALNE NAWIASOWANIE" << std::endl << std::endl;
    std::cout << "[EN] OPTIMAL PARENTHESIZATION" << std::endl << std::endl;
    
    
    wypisz (wymiary_macierzy, indeks_nawiasowania, 0, liczba_macierzy - 1);
    std::cout << std::endl;
    
    
    return 0;
}


void wypisz(const std::vector<int> & wymiary, const std::vector<std::vector<int>> & indeksy, const int poczatek, const int koniec)
{
    if (poczatek >= koniec)
       std::cout << "A" << poczatek + 1;
    else
    {
		 std::cout << "(";
		 wypisz (wymiary, indeksy, poczatek, indeksy[poczatek][koniec]); 
		 std::cout << " * ";
		 wypisz (wymiary, indeksy, indeksy[poczatek][koniec] + 1, koniec);
		 std::cout << ")";
    }
    return;
}

