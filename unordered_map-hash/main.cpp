

#include <unordered_map>

#include "person.h"

int main()
{
   person Janek {"Jan",       "Kowalski",   2241245613};
   person Basia {"Barbara",   "Nowak",      5320346125};
   person Kasia {"Katarzyna", "Matianek",   4222957882};
   person Jacek {"Jacek",     "Studzienny", 5594839222};

   // [PL] Osoba jest kluczem tablicy asocjacyjnej.
   // [EN] Person is a key of the associative table.
   std::unordered_map<person, double, hasher> students;

   // [PL] Studenci mają swoje średnie. | [EN] Student have their grade averages.
   students[Basia] = 4.35;
   students[Janek] = 3.93;
   students[Kasia] = 4.01;

   std::cout << "===============" << std::endl;
   for (const auto & [st, average] : students)
      std::cout << st << ", average: " << average << std::endl;

   std::cout << "===============" << std::endl;
  
   // [PL] Dodajemy jeszcze Jacka. | [EN] Add Jack.
   students[Jacek] = 4.14;
   for (const auto & [st, average] : students)
      std::cout << st << ", average: " << average << std::endl;
   
   std::cout << "===============" << std::endl;
   // [PL] Wypiszmy wartości funkcji haszującej dla studentów. | [EN] Print hash values for students.
   hasher h;   
   for (const auto & [st, average] : students)
      std::cout << st << ", hash: " << h(st) << std::endl;
   
   std::cout << "===============" << std::endl;
   return 0;
}
