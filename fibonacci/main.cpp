
#include <iostream> 
#include <fstream>
#include <string>
#include <chrono>
#include <random>  
#include <memory>
#include <map>

#include "clock.h"
#include "fibonacci.h"
#include "recursive_definition.h"
#include "recursive_dynamic.h" 
#include "iterative_dynamic.h"


#define debug(x)   std::cerr << __FILE__ << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl 

 
int main ()
{
   std::vector<std::shared_ptr<fibonacci>> Fibs
   {
        std::shared_ptr<fibonacci> (new recursive_definition()),
        std::shared_ptr<fibonacci> (new recursive_dynamic()),
        std::shared_ptr<fibonacci> (new iterative_dynamic()),
   };
   
   std::map<std::size_t, std::map<std::string, double>> execution_times;
   
   std::vector<std::vector<int>> arrays;
   
   std::vector<int> numbers = {10, 15, 20, 25, 30, 35, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
   
   
   for (const auto & p : Fibs)
   {
       std::cout << p->get_name() << std::endl;
           auto name = p->get_short_name();
           for (const auto n : numbers)
           {
                ksi::clock time;
                time.start();
                auto value = p->value(n);
                time.stop();
                std::cout << name << ": F(" << n << ") = " << value << std::endl;
                execution_times[n][name] = time.elapsed_milliseconds();
           }
   }
   
   const std::string FILE_NAME {"output.dat"};
   std::ofstream file (FILE_NAME);
   if (file)
   {
        // print header
        file << "size\t";
        for (const auto & iMethod : execution_times.begin()->second)
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

