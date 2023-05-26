
#include <string>
#include <functional>
#include <iostream>

#include "person.h"


person::person (const std::string & first_name, const std::string & surname, const std::size_t id) : _first_name (first_name), _surname (surname), _id (id)
{}

bool person::operator== (const person & p) const
{
   return _first_name == p._first_name and _surname == p._surname and _id == p._id; 
}

std::ostream & operator << (std::ostream & s, const person & os)
{
   return s << os._first_name << ' ' << os._surname << " (" << os._id << ')';
}

std::size_t hasher::operator() (const person & o) const
{


   /*
   std::hash<std::string> h1;
   auto h_first_name = h1(o._first_name);
   auto h_surname    = h1(o._surname);

   std::hash<std::size_t> h2;
   auto h_id         = h2(o._id);

   return h_first_name ^ h_surname ^ h_id;
   */

   // [PL] To samo co wyżej, ale krócej. | [EN] The same as above but shorter. 
   return std::hash<std::string> ()(o._first_name) ^ std::hash<std::size_t>()(o._id) ^ std::hash<std::string> ()(o._surname);
   
   /* [PL] Zamiana lewej i prawej części _id. | [EN] Swap of left and right part of _id.
   unsigned int size = sizeof(o._id);
   std::size_t right = o._id << (size / 2);
   std::size_t left  = o._id >> (size / 2);

   std::size_t id = right | left;

   return std::hash<std::string> ()(o._first_name) ^ std::hash<std::size_t>()(id) ^ std::hash<std::string> ()(o._surname);
  */ 

}

