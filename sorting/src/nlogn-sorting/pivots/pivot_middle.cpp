
#include "pivot_selector.h"
#include "pivot_middle.h"

pivot_middle::pivot_middle ()
{
}

pivot_middle::~pivot_middle ()
{
   // delete what is to delete

}

pivot_middle::pivot_middle (const pivot_middle & wzor) : pivot_selector(wzor)
{
   // copy what is to copy

}

pivot_middle & pivot_middle::operator= (const pivot_middle & wzor)
{
   if (this == & wzor)
      return *this;

   pivot_selector::operator=(wzor);

   // remove what is to remove

   // allocate what is to allocate

   return *this;
}

pivot_middle::pivot_middle (pivot_middle && wzor) : pivot_selector(wzor)
{
   // swap what is to swap

}

pivot_middle & pivot_middle::operator= (pivot_middle && wzor)
{
   if (this == & wzor)
      return *this;

   pivot_selector::operator=(wzor);

   // swap what is to swap

   return *this;
}

int pivot_middle::get_pivot(const std::vector<int>& array, const std::size_t first, const std::size_t past_the_last)
{
    return array[(first + past_the_last) / 2];
}

std::shared_ptr<pivot_selector> pivot_middle::clone() const
{
    return std::shared_ptr<pivot_selector> (new pivot_middle(*this));
}

std::string pivot_middle::get_name() const
{
    return "pivot: middle";
}

std::string pivot_middle::get_short_name() const
{
    return "middle";
}
