
#include <random>
#include <chrono>
#include <iostream>

#include "pivot_selector.h"
#include "pivot_random.h"

#define debug(x)  std::cerr << __FILE__ << " (" << __LINE__ << ") " << #x << " == " << (x) << std::endl 

pivot_random::pivot_random ()
{
    engine = std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count());
}

pivot_random::~pivot_random ()
{
   // delete what is to delete

}

pivot_random::pivot_random (const pivot_random & wzor) : pivot_selector(wzor)
{
   // copy what is to copy

}

pivot_random & pivot_random::operator= (const pivot_random & wzor)
{
   if (this == & wzor)
      return *this;

   pivot_selector::operator=(wzor);

   // remove what is to remove

   // allocate what is to allocate

   return *this;
}

pivot_random::pivot_random (pivot_random && wzor) : pivot_selector(wzor)
{
   // swap what is to swap

}

pivot_random & pivot_random::operator= (pivot_random && wzor)
{
   if (this == & wzor)
      return *this;

   pivot_selector::operator=(wzor);

   // swap what is to swap

   return *this;
}


int pivot_random::get_pivot(const std::vector<int>& array, const std::size_t first, const std::size_t past_the_last)
{
    std::uniform_int_distribution<std::size_t> distro (first, past_the_last - 1);
    return array[distro(engine)];
    
}

std::shared_ptr<pivot_selector> pivot_random::clone() const
{
    return std::shared_ptr<pivot_selector> (new pivot_random(*this));
}

std::string pivot_random::get_name() const
{
    return "pivot: random";
}

std::string pivot_random::get_short_name() const
{
    return "random";
}

