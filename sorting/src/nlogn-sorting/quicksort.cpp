
#include <iostream>

#include "../sorter.h"
#include "./quicksort.h"
#include "./pivots/pivot_selector.h"
 
 

void quicksort::sort(std::vector<int> & numbers, std::size_t begin, std::size_t past_the_end)
{
    if (past_the_end - begin < 2)
        return;
    
    auto pivot_value = pPivotSelector->get_pivot(numbers, begin, past_the_end);
    
    // where is pivot?
    auto current_loc_pivot = begin;
    auto final_loc_pivot = begin;
    for (std::size_t i = begin; i < past_the_end; i++)
    {
        if (numbers[i] < pivot_value)
            final_loc_pivot++;
        else if (numbers[i] == pivot_value)
            current_loc_pivot = i;
    }
    std::swap(numbers[current_loc_pivot], numbers[final_loc_pivot]);
    // pivot in its final position

    // reallocate items
    auto l = begin;
    auto p = past_the_end - 1;
    while (l < p)
    {
        while (numbers[l] < pivot_value)
            l++;
        while (numbers[p] > pivot_value)
            p--;

        if (l < final_loc_pivot and final_loc_pivot < p)
        {
            std::swap(numbers[l], numbers[p]);
            l++;
            p--;
        }
    }  
    
    // recursive calls
    if (begin < final_loc_pivot)
       sort (numbers, begin, final_loc_pivot);
    if (final_loc_pivot < past_the_end - 1)
       sort (numbers, final_loc_pivot + 1, past_the_end);
}

 

std::string quicksort::get_name() const 
{
    return std::string ("quicksort (" + pPivotSelector->get_name() + ")");
}
 
std::string quicksort::get_short_name() const 
{
    return std::string ("quicksort+" + pPivotSelector->get_short_name());
}
 
 
quicksort::~quicksort ()
{
   // delete what is to delete

}

quicksort::quicksort(const pivot_selector& ps)
{
    pPivotSelector = ps.clone();
}


quicksort::quicksort (const quicksort & wzor) : sorter(wzor)
{
   // copy what is to copy
   pPivotSelector = wzor.pPivotSelector == nullptr ? nullptr : wzor.pPivotSelector->clone(); 

}

quicksort & quicksort::operator= (const quicksort & wzor)
{
   if (this == & wzor)
      return *this;

   sorter::operator=(wzor);

   // remove what is to remove

   // allocate what is to allocate
   pPivotSelector = wzor.pPivotSelector == nullptr ? nullptr : wzor.pPivotSelector->clone(); 

   return *this;
}

quicksort::quicksort (quicksort && wzor) : sorter(wzor)
{
   // swap what is to swap
    std::swap(pPivotSelector, wzor.pPivotSelector);

}

quicksort & quicksort::operator= (quicksort && wzor)
{
   if (this == & wzor)
      return *this;

   sorter::operator=(wzor);

   // swap what is to swap

   std::swap(pPivotSelector, wzor.pPivotSelector);
   
   return *this;
} 
