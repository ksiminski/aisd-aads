
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
 
