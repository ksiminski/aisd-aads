
#include <string>
#include <fstream>
#include <unordered_map>
#include <map>
#include <iostream>

#include "clock.h"

/*
[PL] Porównanie czasu wykonania operacji słownikowych (wstawienia) dla tablicy mieszającej i drzewa zrównoważonego.
     Tablica mieszająca jest wykorzystywania do implementacji kontenera std::unordered_map w C++, 
     a zrównoważone drzewo (drzewo czerwono-czarne) -- kontenera std::map.
[EN] The comparison of the execution time of a dictionary operation (insert) for a hash table and a balanced 
     binary tree. A hash table is used to implement the std::unordered_map container in C++, and a balanced
     binary tree (red-black tree) for the std::map container.
*/
 
int main (int size, char ** params)
{
    const std::size_t n = 10'000'000;
    const std::size_t items_to_print = 1000;
    const std::size_t rest = 10000;
    
    ksi::clock stopwatch;
    
    
    std::unordered_map<std::size_t, std::size_t> times_hash_table;     
    std::map<std::size_t, std::size_t>           times_balanced_tree;
   
    // [PL] tablica mieszająca | [EN] hash table
    std::cout << "hash table    " << std::flush;
    stopwatch.start();
    for (std::size_t i = 0; i < n; i++)
    {
        times_hash_table[i] = stopwatch.get_time_microseconds();
    }
    std::cout << " [OK]" << std::endl;
  
    // [PL] drzewo zrównoważone | [EN] balanced tree
     std::cout << "balanced tree " << std::flush;
     stopwatch.start();
     for (std::size_t i = 0; i < n; i++)
     {
         times_balanced_tree[i] = stopwatch.get_time_microseconds();
     }
     std::cout << " [OK]" << std::endl;
    
    // [PL] generowanie danych do wykresu | [EN] save the data for a plot
    std::string file_name ("output.dat");
    std::ofstream file (file_name);
    if (file)
    {
        file << "n\th\tb\n";
        //std::size_t i = 0;
        std::size_t step = n / items_to_print;
        std::size_t prev_hash_table = times_hash_table[0];
        std::size_t prev_balanced_tree = times_balanced_tree[0];
        std::size_t current_hash_table {0};
        std::size_t current_balanced_tree {0};
        
        for (std::size_t i = 1; i < n; i+= step)
        {
            current_hash_table = times_hash_table[i];
            std::size_t diff_hash_table = current_hash_table - prev_hash_table;
            
            current_balanced_tree = times_balanced_tree[i];
            std::size_t diff_balanced_tree = current_balanced_tree - prev_balanced_tree;
            
            file << i << '\t' << diff_hash_table << '\t' << diff_balanced_tree << '\n';
            prev_hash_table = current_hash_table;
            prev_balanced_tree = current_balanced_tree;
        }
    }
    
    return 0;    
}
 
