#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>


/** 
 [PL] Klasa reprezentuje osobę. Klasa jest kluczem (indeksem) dla szablonu unordered_map. 
      Szablon unordered_map jest implementowany jako tablica mieszająca. Operacje słownikowe mają złożoność stałą O(1). 
 [EN] The class represents a person. This class is a key for a unordered_map.
      The unordered_map template is implemented with a tash table. Dictionary operations have contant comlexity O(1).

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

   /** [PL] Trzeba zaimplementować operator porównania, bo równość haszów nie oznacza równości obiektów.
            W przypadku równych haszów trzeba sprawdzić, czy naprawdę mamy takie same obiekty.
       [EN] It is necessary to implement the equality operator, because the equality of hashes does not imply 
            equality of objects. In case of equal hashes, it is necessary to test if the object are equal.
   */
   bool operator== (const person & p) const ;

   friend
   std::ostream & operator << (std::ostream & s, const person & os);

   /** [PL] Zaprzyjaźniona struktura implementująca wyznaczanie wartości funkcji haszującej dla klasy person.
            Jest to obiekt funkcyjny.
       [EN] A friend structure implemeneting a hash function for the person class. 
            It is a function object.
   */
   friend 
   struct hasher;
};


struct hasher
{
   /** [PL] Obiekt funkcyjny implementuje operator() dla obiektów klasy person.
       [EN] The function object implement the operator() for object of the person class. 
   */
   std::size_t operator() (const person & o) const;
};

#endif
