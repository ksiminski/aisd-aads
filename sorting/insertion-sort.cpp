

#include <array>
#include "sorter.h"
#include "insertion-sort.h"

 

void insertion_sort::sort(std::vector<int> & numbers, std::size_t begin, std::size_t past_the_end)
{
    std::size_t size = numbers.size();
    for (std::size_t i = 1; i < size; i++)
    {
        int minimum = numbers[i];
        std::size_t j = i;
        while (j > 0 and minimum < numbers[j - 1]) 
        {
            numbers[j] = numbers[j - 1];
            j--;
        }
        numbers[j] = minimum;
    }
}

insertion_sort::~insertion_sort()
{
}

std::string insertion_sort::get_name() const
{
    return std::string ("insertion-sort");
}

std::string insertion_sort::get_short_name() const
{
    return get_name();
}

 
