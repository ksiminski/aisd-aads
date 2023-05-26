
#include <string>
#include <functional>
#include <iostream>

#include "person.h"


person::person (const std::string & first_name, const std::string & surname, const std::size_t id) : _first_name (first_name), _surname (surname), _id (id)
{}

bool person::operator< (const person & p) const
{
   if (_surname == p._surname)
   {
      if (_first_name == p._first_name)
         return _id < p._id;
      else 
         return _first_name < p._first_name;
   } 
   else 
      return _surname < p._surname;
}

std::ostream & operator << (std::ostream & s, const person & os)
{
   return s << os._first_name << ' ' << os._surname << " (" << os._id << ')';
}

