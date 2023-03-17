

/*
[PL] Wektor z biblioteki STL (std::vector) jest zoptymalizowany dla dodawania na końcu (metoda push_back). W przypadku dodawania nowego elementu do pełnego wektora, wektor jest realokowany i jego rozmiar (capacity) podwaja się. Dzięki temu dodawanie n elementów po kolei (koszt zamortyzownay) ma złożoność liniową O(n). Oznacza to, że koszt zamortyzowany dodania elementu na końcu wektora jest stały. Program eksperymentalnie sprawdza, czy tak jest naprawdę. 

[EN] The STL vector (std::vector) is optimised for adding new item at its end (the push_back method). If a new item is to be inserted to a full vector, the capacity of the vector is doubled. This is why the cost of insertion n items one by one (amortised cost) is linear O(n). It means the amortised cost of insertion of one item is constant. The program runs an experiment to test if it is true. 

*/

#include <string>
#include <fstream>
#include <vector>
#include <iostream>

#include "clock.h"

 
int main (int size, char ** params)
{
    const std::size_t n = 100000000;
    const std::size_t items_to_print = 1000;
    const std::size_t rest = 10000;
    
    ksi::clock stopwatch;
    std::vector<std::size_t> vector;
    
    stopwatch.start();
    for (std::size_t i = 0; i < n; i++)
    {
        vector.push_back(stopwatch.get_time_milliseconds());
    }
    
    std::string file_name ("output.dat");
    std::ofstream file (file_name);
    if (file)
    {
        file << "n\tt\n";
        std::size_t i = 0;
        std::size_t step = n / items_to_print;
        for (std::size_t i = 0; i < vector.size(); i += step)
        {
            file << i << '\t' << vector[i] % rest << '\n';
        }
    }
    
    return 0;    
}
 
