
#include <iostream>

#include "pivot_median_of_3.h"
#include "pivot_median_of_3_medians_of_3.h"

#define debug(x)  std::cerr << __FILE__ << " (" << __LINE__ << ") " << #x << " == " << (x) << std::endl 


pivot_median_of_3_medians_of_3::pivot_median_of_3_medians_of_3 ()
{
}

pivot_median_of_3_medians_of_3::~pivot_median_of_3_medians_of_3 ()
{
   // delete what is to delete

}

pivot_median_of_3_medians_of_3::pivot_median_of_3_medians_of_3 (const pivot_median_of_3_medians_of_3 & wzor) : pivot_median_of_3(wzor)
{
   // copy what is to copy

}

pivot_median_of_3_medians_of_3 & pivot_median_of_3_medians_of_3::operator= (const pivot_median_of_3_medians_of_3 & wzor)
{
   if (this == & wzor)
      return *this;

   pivot_median_of_3::operator=(wzor);

   // remove what is to remove

   // allocate what is to allocate

   return *this;
}

pivot_median_of_3_medians_of_3::pivot_median_of_3_medians_of_3 (pivot_median_of_3_medians_of_3 && wzor) : pivot_median_of_3(wzor)
{
   // swap what is to swap

}

pivot_median_of_3_medians_of_3 & pivot_median_of_3_medians_of_3::operator= (pivot_median_of_3_medians_of_3 && wzor)
{
   if (this == & wzor)
      return *this;

   pivot_median_of_3::operator=(wzor);

   // swap what is to swap

   return *this;
}

int pivot_median_of_3_medians_of_3::get_pivot(const std::vector<int>& array, const std::size_t first, const std::size_t past_the_last)
{
    auto _1 = pivot_median_of_3::get_pivot(array, first, past_the_last); 
    auto _2 = pivot_median_of_3::get_pivot(array, first, past_the_last); 
    auto _3 = pivot_median_of_3::get_pivot(array, first, past_the_last); 
    
    return median(_1, _2, _3);
}

std::shared_ptr<pivot_selector> pivot_median_of_3_medians_of_3::clone() const
{
    return std::shared_ptr<pivot_selector> (new pivot_median_of_3_medians_of_3(*this));
}

std::string pivot_median_of_3_medians_of_3::get_name() const
{
    return "pivot: median of 3 medians of 3";
}

std::string pivot_median_of_3_medians_of_3::get_short_name() const
{
    return "m3m3";
}
