
#include <cmath>

#include "gap_generator.h"
#include "gaps_shell.h"

gaps_shell::gaps_shell ()
{
}

gaps_shell::~gaps_shell ()
{
   // delete what is to delete

}

gaps_shell::gaps_shell (const gaps_shell & wzor) : gap_generator(wzor)
{
   // copy what is to copy

}

gaps_shell & gaps_shell::operator= (const gaps_shell & wzor)
{
   if (this == & wzor)
      return *this;

   gap_generator::operator=(wzor);

   // remove what is to remove

   // allocate what is to allocate

   return *this;
}

gaps_shell::gaps_shell (gaps_shell && wzor) : gap_generator(wzor)
{
   // swap what is to swap

}

gaps_shell & gaps_shell::operator= (gaps_shell && wzor)
{
   if (this == & wzor)
      return *this;

   gap_generator::operator=(wzor);

   // swap what is to swap

   return *this;
}

std::shared_ptr<gap_generator> gaps_shell::clone() const
{
    return std::shared_ptr<gap_generator> (new gaps_shell(*this));
}


std::size_t gaps_shell::get_first_gap(const std::size_t N)
{
    _N = N;
    divisor = 2;
    return std::floor(_N / divisor);
    
}

std::size_t gaps_shell::get_next_gap()
{
    divisor *= 2;
    return std::floor(_N / divisor);
}

std::string gaps_shell::get_name() const
{
    return "Shell sequence";
}

std::string gaps_shell::get_short_name() const
{
    return "shell";
}
