

#include <unordered_map>

#include "osoba.h"

int main()
{
   osoba Janek {"Jan",       "Kowalski",   2241245613};
   osoba Basia {"Barbara",   "Nowak",      5320346125};
   osoba Kasia {"Katarzyna", "Matianek",   4222957882};
   osoba Jacek {"Jacek",     "Studzienny", 5594839222};

   std::unordered_map<osoba, double, hasher> studenci;

   studenci[Basia] = 4.35;
   studenci[Janek] = 3.93;
   studenci[Kasia] = 4.01;

   std::cout << "===============" << std::endl;
   for (const auto & [st, srednia] : studenci)
      std::cout << st << ", srednia: " << srednia << std::endl;

   std::cout << "===============" << std::endl;
   
   studenci[Jacek] = 4.14;
   for (const auto & [st, srednia] : studenci)
      std::cout << st << ", srednia: " << srednia << std::endl;
   
   std::cout << "===============" << std::endl;
   hasher h;   
   for (const auto & [st, srednia] : studenci)
      std::cout << st << ", hasz: " << h(st) << std::endl;
   
   std::cout << "===============" << std::endl;
   return 0;
}
