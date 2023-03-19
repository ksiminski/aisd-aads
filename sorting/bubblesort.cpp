

#include <array>
#include "sorter.h"
#include "bubblesort.h"

 
bubblesort::~bubblesort()
{
}

void bubblesort::sort(std::vector<int> & numbers, std::size_t begin, std::size_t part_the_end)
{
    std::size_t size = numbers.size();
    for (std::size_t i = 0; i < size; i++)
    {
        for (std::size_t j = 1; j < size; j++)
        {
            if (numbers[j - 1] > numbers[j])
                std::swap(numbers[j - 1], numbers[j]);
        }
    }
}

std::string bubblesort::get_name() const 
{
    return std::string ("bubblesort");
}

std::string bubblesort::get_short_name() const 
{
    return get_name();
}



 
