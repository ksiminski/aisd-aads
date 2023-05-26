#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>


/** 
 [PL] Klasa reprezentuje osobę. Klasa jest kluczem (indeksem) dla szablonu map. 
      Szablon map jest implementowany jako zrównoważone drzewo binarne. Operacje słownikowe mają złożoność logarytmiczną O(log n). 
 [EN] The class represents a person. This class is a key for a map.
      The map template is implemented with a balanced binary tree. Dictionary operations have contant comlexity O(log n).

    @date   2023-05-26
    @author Krzysztof Siminski
*/
class person
{
   std::string _first_name;
   std::string _surname;
   std::size_t _id;

   public:
   /**  */
   person (const std::string & first_name, const std::string & _surname, const std::size_t id);

   /** [PL] Trzeba zaimplementować operator mniejszości, bo mapa jest uporządkowana.
       [EN] It is necessary to implement the less than operator, because the map is ordered.
   */
   bool operator< (const person & p) const ;

   friend
   std::ostream & operator << (std::ostream & s, const person & os);

};


#endif
