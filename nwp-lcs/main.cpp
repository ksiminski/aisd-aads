
////////////////////////////////////////
// [PL] Najdluzszy wspolnego podciag 
// [EN] The longest common sequence 
// Krzysztof Siminski, 2024-04-28
////////////////////////////////////////

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/////////////////////////

enum class direction { upper, left, diagonal, none };

std::pair<std::size_t, std::string> lsc (const std::string & X, const std::string & Y)
{
   auto size_X = X.size();
   auto size_Y = Y.size();

   // [PL] alokacja macierzy | [EN] matrix allocation
   std::vector<std::vector<std::size_t>> lengths    (size_Y + 1, std::vector<std::size_t> (size_X + 1, 0));
   std::vector<std::vector<direction>>   directions (size_Y + 1, std::vector<direction> (size_X + 1));

   // [PL] przygotowanie macierzy | [EN] matrix preparation
   for (std::size_t y = 0; y < size_Y + 1; ++y)
   {
      lengths[y][0] = 0;
      directions[y][0] = direction::none;
   }

   for (std::size_t x = 0; x < size_X + 1; ++x)
   {
      lengths[0][x] = 0;
      directions[0][x] = direction::none;
   }

   // [PL] znalezienie najdluzszego wspolnego podciagu
   // [EN] elaboration of the longest common subsequence
   for (std::size_t y = 1; y < size_Y + 1; ++y)
   {
      for (std::size_t x = 1; x < size_X + 1; ++x)
      {
         if (X[x - 1] == Y[y - 1])
         {
            lengths[y][x] = lengths[y - 1][x - 1] + 1;
            directions[y][x] = direction::diagonal;
         }
         else if (lengths[y - 1][x] >= lengths[y][x - 1]) 
         {
            lengths[y][x] = lengths[y - 1][x];
            directions[y][x] = direction::upper;
         }
         else 
         {
            lengths[y][x] = lengths[y][x - 1];
            directions[y][x] = direction::left;
         }
      }
   }


   // [PL] wypisanie najdluzszego wspolnego podciagu
   // [EN] printing of the longest common subsequence
   auto length = lengths.back().back();

   std::size_t y = directions.size();
   std::size_t x = directions.front().size();
   x--; y--;

   std::string common_sequence;

   while (directions[y][x] != direction::none)
   {
      switch (directions[y][x])
      {
         case direction::diagonal: 
            common_sequence.push_back(X[x - 1]);
            x--; y--;
            break;
         case direction::left:
            x--;
            break;
         case direction::upper:
            y--;
            break;
      }
   }
   std::reverse(common_sequence.begin(), common_sequence.end());
   return {length, common_sequence};
}

void help (int nParams, char ** params)
{
   std::cout << "============================" << std::endl;
   std::cout << "[PL]" << std::endl;
   std::cout << "Najdluzszy wspolny podciag dwoch ciagow." << std::endl << std::endl;
   std::cout << "uruchomienie programu: " << std::endl << params[0] << " pierwszy drugi" << std::endl;
   std::cout << "gdzie pierwszy i drugi sa napisami." << std::endl;
   std::cout << "Najdluzszy wspolny podciag jest wypisywany na standardowe wyjscie." << std::endl;
   std::cout << "============================" << std::endl;

   std::cout << "[EN]" << std::endl;
   std::cout << "The longest common subsequence." << std::endl << std::endl;
   std::cout << "to run a program: " << std::endl << params[0] << " first second" << std::endl;
   std::cout << "where first and second are string sequences." << std::endl;
   std::cout << "The longest common subsequence is printed to the standard output." << std::endl;
   std::cout << "============================" << std::endl;

   return ;
}
/////////////////////////
int main (int nParams, char ** params)
{
   if (nParams != 3)
   {
      help(nParams, params);
      return 0;
   }

   std::string first  {params[1]};
   std::string second {params[2]};

   const auto & [length, sequence] = lsc(first, second);
   std::cout << "[PL] najdluzszy wspolny podciag (NWP)" << std::endl;
   std::cout << "[EN] the longest common subsequence (LCS)" << std::endl;
   std::cout << "wejscie/input:  " << first << "\t" << second << std::endl;
   std::cout << "dlugosc/length: " << length << std::endl;
   std::cout << "NWP/LCS:        " << sequence << std::endl;
   std::cout << std::endl;

   return 0;
}

