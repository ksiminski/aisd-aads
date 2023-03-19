
#include <cmath>
#include <iostream>

#include "gap_generator.h"
#include "gaps_frank.h"

#define debug(x) std::cerr << __FILE__ << " [" << __FUNCTION__ << "] (" << __LINE__ << ") " << #x << " == " << (x) << std::endl

gaps_frank::gaps_frank ()
{
}

gaps_frank::~gaps_frank ()
{
   // delete what is to delete

}

gaps_frank::gaps_frank (const gaps_frank & wzor) : gap_generator(wzor)
{
   // copy what is to copy

}

gaps_frank & gaps_frank::operator= (const gaps_frank & wzor)
{
   if (this == & wzor)
      return *this;

   gap_generator::operator=(wzor);

   // remove what is to remove

   // allocate what is to allocate

   return *this;
}

gaps_frank::gaps_frank (gaps_frank && wzor) : gap_generator(wzor)
{
   // swap what is to swap

}

gaps_frank & gaps_frank::operator= (gaps_frank && wzor)
{
   if (this == & wzor)
      return *this;

   gap_generator::operator=(wzor);

   // swap what is to swap

   return *this;
}

std::shared_ptr<gap_generator> gaps_frank::clone() const
{
     return std::shared_ptr<gap_generator> (new gaps_frank(*this));
}


std::size_t gaps_frank::get_first_gap(const std::size_t N)
{
    _N = N;
    mianownik = 4;
    return 2 * std::floor(_N / mianownik) + 1;
    
}

std::size_t gaps_frank::get_next_gap()
{
    mianownik *= 2;
    return 2 * std::floor(_N / mianownik) + 1;
}

std::string gaps_frank::get_name() const
{
    return "Frank sequence";
}

std::string gaps_frank::get_short_name() const
{
    return "frank";
}
