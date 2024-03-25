////////////////////////////////////////////////
// [PL] przykład haszowania łańcuchowego w C++
// [EN] example of chain hashing in C++
////////////////////////////////////////////////


#include <iostream>
#include <unordered_map>

template <class K, class T>
void run (const std::unordered_map<K, T> & dict)
{
   std::cout << "size: " << dict.size() << std::endl;
   std::cout << "buckets: " << dict.bucket_count() << std::endl;
   std::cout << "load factor: " << dict.load_factor() << std::endl;
   std::cout << "max load factor: " << dict.max_load_factor() << std::endl;

   std::cout << "================" << std::endl;
   std::cout << "print all values" << std::endl;
   std::cout << "================" << std::endl;
   for (auto it = dict.begin(); it != dict.end(); ++it)
      std::cout << it-> first << " : " << it->second << std::endl;

   std::cout << "=================" << std::endl;
   std::cout << "print all buckets" << std::endl;
   std::cout << "=================" << std::endl;
   for (unsigned int i = 0; i < dict.bucket_count(); ++i)
   {
      std::cout << "bucket " << i << " (size: " << dict.bucket_size(i) << ") : ";
      for (auto it = dict.begin(i); it != dict.end(i); ++it)
         std::cout << "[ " << it-> first << " : " << it->second << " ] ";
      std::cout << std::endl;
   }
   std::cout << "===============" << std::endl;
}

int main()
{

   {
      std::cout << "============================================" << std::endl;
      std::cout << "std::unordered_map<std::string, std::string>" << std::endl;
      std::cout << "============================================" << std::endl;

      std::unordered_map<std::string, std::string> dict
      {
         {"zero", "zero"},
            {"jeden", "one"},
            {"dwa", "two"},
            {"trzy", "three"},
            {"cztery", "four"},
            {"piec", "five"},
            {"szesc", "six"},
            {"siedem", "seven"}, 
            {"osiem", "eight"},
            {"dziewiec", "nine"},
            {"dziesiec", "ten"},
            {"jedenascie", "eleven"},
            {"dwanascie", "twelve"},
            {"trzynascie", "thirteen"},
            {"ostatni", "last"}
      };

      run(dict);

      std::cout << std::endl;
   }
   //////////////////////////////////
   {

      std::cout << "============================" << std::endl;
      std::cout << "std::unordered_map<int, int>" << std::endl;
      std::cout << "============================" << std::endl;

      std::unordered_map<int, int> dict;

      for (int i = 0; i < 140; ++i)
         dict[i] = 10 * i + 1;

      run (dict);

      std::cout << std::endl;
   }
   //////////////////////////////////
   {
      std::cout << "==================================" << std::endl;
      std::cout << "std::unordered_map<double, double>" << std::endl;
      std::cout << "==================================" << std::endl;

      std::unordered_map<double, double> dict;

      for (int i = 0; i < 140; ++i)
      {
         double d = i;
         d += d / 1000;
         dict[d] = 1.0 / (d + 1);
      }
      // dict.max_load_factor(3);

      run (dict);

      std::cout << std::endl;
   }
   return 0;
}
