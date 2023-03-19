
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <random>
#include <memory> 
#include <vector>
#include <map>

#include "clock.h"
#include "sorter.h"
#include "mergesort.h"
#include "selection-sort.h" 
#include "insertion-sort.h"
#include "shellsort.h"
#include "heapsort.h"
#include "quicksort.h"
#include "bubblesort.h"


#include "pivot_first.h"
#include "pivot_last.h"
#include "pivot_median_of_3.h"
#include "pivot_median_of_3_medians_of_3.h"
#include "pivot_middle.h"
#include "pivot_random.h"


#include "gaps_frank.h"
#include "gaps_shell.h"

#define debug(x)   std::cerr << __FILE__ << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl 

 
std::vector<int> get_numbers (const std::size_t  SIZE)
{
   static  std::default_random_engine engine (std::chrono::system_clock::now().time_since_epoch().count());
   std::vector<int> numbers (SIZE);
   std::iota(numbers.begin(), numbers.end(), 1);
   std::shuffle (numbers.begin(), numbers.end(), engine);
   
   return numbers;
}
 
void print (const std::vector<int> & w)
{
    std::cout << "[ ";
    for (const auto & d : w)
        std::cout << d << " ";
    std::cout << "]" << std::endl;
}

int main ()
{
//    pivot_first pivot;
//    pivot_last pivot;
//    pivot_median_of_3 pivot;
//    pivot_median_of_3_medians_of_3 pivot;
//    pivot_middle pivot;
//    pivot_random pivot;
   
//    gaps_shell sequence;
//    gaps_frank sequence;
 
   std::vector<std::shared_ptr<sorter>> sorters
   {
//         std::shared_ptr<sorter> (new mergesort),
//        std::shared_ptr<sorter> (new quicksort(pivot)),
        std::shared_ptr<sorter> (new bubblesort),
        std::shared_ptr<sorter> (new insertion_sort),
//        std::shared_ptr<sorter> (new shellsort(sequence)),  // wstrzykiwanie zaleznosci
//         std::shared_ptr<sorter> (new heapsort),
//         std::shared_ptr<sorter> (new mergesort),
         std::shared_ptr<sorter> (new selection_sort),
   };
   
   
   std::map<std::size_t, std::map<std::string, double>> execution_times;
   
   std::vector<std::vector<int>> arrays;
   

//     for (const auto n : {10})
//        for (const auto n : {1'000, 2'000, 4'000, 8'000})
   for (const auto n : {1'000, 10'000, 20'000, 30'000, 40'000, 50'000})
//  for (const auto n : {10'000, 100'000, 200'000, 300'000, 400'000, 500'000})
//    for (const auto n : {200'000, 400'000, 800'000, 1600'000, 3200'000})
//    for (const auto n : {2000'000, 4000'000, 8000'000, 16000'000, 32000'000})
   {
       arrays.push_back(get_numbers(n));
   }


   //arrays.push_back({1,2,3,4,5});

   for (const auto p : sorters)
   {
       std::cout << p->get_name() << std::endl;
       for (const auto tab : arrays)
       {
           auto size = tab.size();
           std::cout << "\t" << size << " " << std::flush;
           auto arr = tab;
           ksi::clock zegar;
           zegar.start();
           p->sort(arr, 0, arr.size());
           zegar.stop();
           
           execution_times[size][p->get_short_name()] = zegar.elapsed_milliseconds();
           
           bool result = std::is_sorted(arr.begin(), arr.end());
           if (result)
              std::cout << "OK" << std::endl;
           else 
              std::cout << "FAILED" << std::endl;
//            wypisz(arr);
    
       }
   }
   
 
   
   const std::string FILE_NAME {"output.dat"};
   std::ofstream file (FILE_NAME);
   if (file)
   {
        // print header
        file << "size\t";
        for (const auto iMethod : execution_times.begin()->second)
        {
            file << iMethod.first << "\t";
        }
        file << std::endl;
        
        // print table
        for (const auto & iSize : execution_times)
        {
            file << iSize.first << "\t";
            for (const auto & iMethod : iSize.second)
            {
                file << iMethod.second << "\t";
            }
            file << std::endl;
        }
   }
   
   return 0; 
}

