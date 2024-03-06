

#include <array>
#include "../sorter.h"
#include "./shellsort.h"

 

void shellsort::sort(std::vector<int> & numbers, std::size_t begin, std::size_t past_the_end)
{
    std::size_t size = numbers.size();
 
    std::size_t h = pGaps->get_first_gap(size); 
    
    while (h > 0)
    {
        for (std::size_t i = h; i < size; i++)
        {
            int minimum = numbers[i];
            std::size_t j = i;
            while (j > h - 1 and minimum < numbers[j - 1]) 
            {
                numbers[j] = numbers[j - h];
                j = j - h;
            }
            numbers[j] = minimum;
        }
        if (h == 1)
            return;  
        h = pGaps->get_next_gap();
    }
}

 

std::string shellsort::get_name() const 
{
    return std::string ("shellsort (" + pGaps->get_name() + ")");
}

std::string shellsort::get_short_name() const 
{
    return std::string ("shellsort+" +pGaps->get_short_name());
}



shellsort::~shellsort ()
{
   // delete what is to delete

}

shellsort::shellsort (const shellsort & wzor) 
{
   // copy what is to copy
    pGaps = wzor.pGaps->clone();

}

shellsort & shellsort::operator= (const shellsort & wzor)
{
   if (this == & wzor)
      return *this;


   // remove what is to remove

   // allocate what is to allocate
   pGaps = wzor.pGaps->clone();

   return *this;
}

shellsort::shellsort (shellsort && wzor)
{
   // swap what is to swap
   std::swap (pGaps, wzor.pGaps);
}

shellsort & shellsort::operator= (shellsort && wzor)
{
   if (this == & wzor)
      return *this;


   // swap what is to swap
   std::swap (pGaps, wzor.pGaps);
   
   return *this;
}
 
shellsort::shellsort(const gap_generator& gap)
{
    pGaps = gap.clone();
}
