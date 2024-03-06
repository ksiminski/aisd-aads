
#include "pivot_selector.h"
#include "pivot_last.h"

pivot_last::pivot_last ()
{
}

pivot_last::~pivot_last ()
{
   // delete what is to delete

}

pivot_last::pivot_last (const pivot_last & wzor) : pivot_selector(wzor)
{
   // copy what is to copy

}

pivot_last & pivot_last::operator= (const pivot_last & wzor)
{
   if (this == & wzor)
      return *this;

   pivot_selector::operator=(wzor);

   // remove what is to remove

   // allocate what is to allocate

   return *this;
}

pivot_last::pivot_last (pivot_last && wzor) : pivot_selector(wzor)
{
   // swap what is to swap

}

pivot_last & pivot_last::operator= (pivot_last && wzor)
{
   if (this == & wzor)
      return *this;

   pivot_selector::operator=(wzor);

   // swap what is to swap

   return *this;
}


int pivot_last::get_pivot(const std::vector<int>& array, const std::size_t first, const std::size_t past_the_last)
{
    return array[past_the_last - 1];
}


std::shared_ptr<pivot_selector> pivot_last::clone() const
{
    return std::shared_ptr<pivot_selector> (new pivot_last(*this));
}

std::string pivot_last::get_name() const
{
    return "pivot: last";
}

std::string pivot_last::get_short_name() const
{
    return "last";
}
