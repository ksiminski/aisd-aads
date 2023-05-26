#ifndef OSOBA_H
#define OSOBA_H

#include <string>
#include <iostream>

class osoba
{
   std::string _imie, _nazwisko;
   std::size_t _album;

   public:
   osoba (const std::string & imie, const std::string & nazwisko, const std::size_t album);

   bool operator== (const osoba & p) const ;

   friend
   std::ostream & operator << (std::ostream & s, const osoba & os);

   friend 
   struct hasher;
};


struct hasher
{
   std::size_t operator() (const osoba & o) const;
};

#endif
