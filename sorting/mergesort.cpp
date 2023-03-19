
#include <iostream>

#include "sorter.h"
#include "mergesort.h"

 

void mergesort::sort(std::vector<int> & numbers, std::size_t begin, std::size_t past_the_end)
{
   if (past_the_end < begin)
      return;
    
   std::size_t size = past_the_end - begin;
   if (size < 2)
       return;

   
   // split 
   std::size_t split = (past_the_end + begin) / 2;
   sort (numbers, begin, split);
   sort (numbers, split, past_the_end);
   
   // merge 
   
   std::vector<int> t (size);
   std::size_t left = begin;
   std::size_t right = split;
   for (std::size_t i = 0; i < size; i++)
   {
      if (left >= split)
         t[i] = numbers[right++];
      else if (right >= past_the_end)
         t[i] = numbers[left++];
      else if (numbers[left] < numbers[right])
         t[i] = numbers[left++];
      else
         t[i] = numbers[right++];
   }
   
   // copying
   for (std::size_t i = 0; i < size; i++)
      numbers[begin + i] = t[i];
   
}

mergesort::~mergesort()
{
}

std::string mergesort::get_name() const
{
    return std::string ("mergesort");
}
 
std::string mergesort::get_short_name() const
{
    return get_name();
}
