

#include <array>
#include "../sorter.h"
#include "./selection-sort.h"

 
selection_sort::~selection_sort()
{
}

void selection_sort::sort(std::vector<int> & numbers, std::size_t begin, std::size_t part_the_end)
{
    std::size_t size = numbers.size();
    for (std::size_t i = 0; i < size; i++)
    {
        int iMin = i;
        
        for (std::size_t j = i + 1; j < size; j++)
        {
            if (numbers[j] < numbers[iMin])
                iMin = j;
        }
        std::swap(numbers[i], numbers[iMin]);
    }
}

std::string selection_sort::get_name() const 
{
    return std::string ("selection-sort");
}

std::string selection_sort::get_short_name() const 
{
    return get_name();
}



 
