
#include <iostream>

#include "pivot_selector.h"
#include "pivot_first.h"


#define debug(x)  std::cerr << __FILE__ << " (" << __LINE__ << ") " << #x << " == " << (x) << std::endl 


pivot_first::pivot_first ()
{
}

pivot_first::~pivot_first ()
{
   // delete what is to delete

}

pivot_first::pivot_first (const pivot_first & wzor) : pivot_selector(wzor)
{
   // copy what is to copy

}

pivot_first & pivot_first::operator= (const pivot_first & wzor)
{
   if (this == & wzor)
      return *this;

   pivot_selector::operator=(wzor);

   // remove what is to remove

   // allocate what is to allocate

   return *this;
}

pivot_first::pivot_first (pivot_first && wzor) : pivot_selector(wzor)
{
   // swap what is to swap

}

pivot_first & pivot_first::operator= (pivot_first && wzor)
{
   if (this == & wzor)
      return *this;

   pivot_selector::operator=(wzor);

   // swap what is to swap

   return *this;
}


int pivot_first::get_pivot(const std::vector<int>& array, const std::size_t first, const std::size_t past_the_last)
{
    return array[first];
}


std::shared_ptr<pivot_selector> pivot_first::clone() const
{
    return std::shared_ptr<pivot_selector> (new pivot_first(*this));
}

std::string pivot_first::get_name() const
{
    return "pivot: first";
}

std::string pivot_first::get_short_name() const
{
    return "first";
}
