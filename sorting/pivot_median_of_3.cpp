
#include <iostream>

#include "pivot_random.h"
#include "pivot_median_of_3.h"

#define debug(x)  std::cerr << __FILE__ << " (" << __LINE__ << ") " << #x << " == " << (x) << std::endl 


pivot_median_of_3::pivot_median_of_3 ()
{
}

pivot_median_of_3::~pivot_median_of_3 ()
{
   // delete what is to delete

}

pivot_median_of_3::pivot_median_of_3 (const pivot_median_of_3 & wzor) : pivot_random(wzor)
{
   // copy what is to copy

}

pivot_median_of_3 & pivot_median_of_3::operator= (const pivot_median_of_3 & wzor)
{
   if (this == & wzor)
      return *this;

   pivot_random::operator=(wzor);

   // remove what is to remove

   // allocate what is to allocate

   return *this;
}

pivot_median_of_3::pivot_median_of_3 (pivot_median_of_3 && wzor) : pivot_random(wzor)
{
   // swap what is to swap

}

pivot_median_of_3 & pivot_median_of_3::operator= (pivot_median_of_3 && wzor)
{
   if (this == & wzor)
      return *this;

   pivot_random::operator=(wzor);

   // swap what is to swap

   return *this;
}

int pivot_median_of_3::median(const int _1, const int _2, const int _3)
{
    if ((_1 <= _2 and _2 <= _3) or (_3 <= _2 and _2 <= _1))
        return _2;
    else if ((_2 <= _1 and _1 <= _3) or (_3 <= _1 and _1 <= _2))
        return _1; 
    else 
        return _3;
}


int pivot_median_of_3::get_pivot(const std::vector<int>& array, const std::size_t first, const std::size_t past_the_last)
{
    auto _1 = pivot_random::get_pivot(array, first, past_the_last);
    auto _2 = pivot_random::get_pivot(array, first, past_the_last);
    auto _3 = pivot_random::get_pivot(array, first, past_the_last);
    
    return median(_1, _2, _3);        
}

std::shared_ptr<pivot_selector> pivot_median_of_3::clone() const
{
    return std::shared_ptr<pivot_selector> (new pivot_median_of_3(*this));
}

std::string pivot_median_of_3::get_name() const
{
    return "pivot: median of 3";
}


std::string pivot_median_of_3::get_short_name() const
{
    return "m3";
}

