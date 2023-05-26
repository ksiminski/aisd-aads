
#include <string>
#include <functional>
#include <iostream>

#include "osoba.h"


osoba::osoba (const std::string & imie, const std::string & nazwisko, const std::size_t album) : _imie (imie), _nazwisko (nazwisko), _album (album)
{}

bool osoba::operator== (const osoba & p) const
{
   return _imie == p._imie and _nazwisko == p._nazwisko and _album == p._album; 
}

std::ostream & operator << (std::ostream & s, const osoba & os)
{
   return s << os._imie << ' ' << os._nazwisko << " (" << os._album << ')';
}

std::size_t hasher::operator() (const osoba & o) const
{
   /*   
   unsigned int rozmiar = sizeof(o._album);
   std::size_t prawa = o._album << (rozmiar / 2);
   std::size_t lewa  = o._album >> (rozmiar / 2);

   std::size_t album = prawa | lewa;

   return std::hash<std::string> ()(o._imie) ^ std::hash<std::size_t>()(album) ^ std::hash<std::string> ()(o._nazwisko);
  */ 

   return std::hash<std::string> ()(o._imie) ^ std::hash<std::size_t>()(o._album) ^ std::hash<std::string> ()(o._nazwisko);
}

