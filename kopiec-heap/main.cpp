////////////////////////////////////////////////
// [PL] czas kopcowanie w funkcji rozmiaru kopca 
// [EN] make heap execution time in function of heap size
////////////////////////////////////////////////


#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#include "clock.h"
#include <random>
#include <chrono> 

std::vector<int> get_random_vector(const std::size_t size) 
{
   std::vector<int> v(size);
   std::default_random_engine rd(std::chrono::system_clock::now().time_since_epoch().count());
   std::uniform_int_distribution<> dis(0, size);
   std::generate(v.begin(), v.end(), [&]() { return dis(rd); });

   return v; 
}

int main(int argc, char ** params)
{
   std::string output_file ("output.dat");
   if (argc == 2)
   {
      output_file = params[1];
   }

   // [PL] przygotowanie danych | [EN] data preparation
   std::size_t size = 100'000'000;
   std::size_t repetitions =   10;
   auto step = size / repetitions;

   std::vector<std::size_t> sizes (repetitions); 
   std::ranges::iota(sizes.begin(), sizes.end(), 1);
   std::transform(sizes.begin(), sizes.end(), sizes.begin(), [step](auto i) { return i * step; });

   auto numbers = get_random_vector(size); 
   std::vector<std::size_t> times;

   // [PL] pomiary | [EN] measurements
   ksi::clock clock; 
   for (auto s : sizes) 
   {
      clock.start();
      std::make_heap (numbers.begin(), numbers.begin() + s);
      clock.stop();
      auto time = clock.get_time_milliseconds();
      times.push_back(time);
      std::cout << "Make heap time for " << s << " elements: " << time << " [ms]" << std::endl;
   }

   // [PL] generowanie danych do wykresu | [EN] save the data for a plot
   std::ofstream file (output_file);
   if (file)
   {
      file << "n\tt\n";

      auto size = times.size();
      for (std::size_t i = 0; i < size; ++i)
      {
         file << sizes[i] << '\t' << times[i] << '\n'; 
      }
   }

   return 0;
}
