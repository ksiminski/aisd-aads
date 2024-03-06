
#include <limits>
#include <cmath>
#include <iostream>

#include "../sorter.h"
#include "./heapsort.h"

#define debug(x) std::cerr << __FILE__ << " [" << __FUNCTION__ << "] (" << __LINE__ << ") " << #x << " == " << (x) << std::endl

 

void heapsort::heapify(std::vector<int>& numbers, std::size_t begin, std::size_t past_the_end)
{
    std::size_t start = std::floor ((past_the_end - 1) / 2);
    while (start >= 0)
    {
        sift_down (numbers, start, past_the_end);
        if (start == 0) 
            return;
        else 
            start--;
    }
} 
 
void heapsort::sift_down(std::vector<int>& numbers, std::size_t begin, std::size_t past_the_end)
{
    const size_t MAX = std::numeric_limits<std::size_t>::max();
    auto parent = begin;
    
    while (parent * 2 + 1 < past_the_end)
    {
        auto child = parent * 2 + 1;
        auto greater_child = MAX;
        if (numbers[parent] < numbers[child])
            greater_child = child;
    
        if (child + 1 < past_the_end)
        {
            if (numbers[parent] < numbers[child + 1] and numbers[child] < numbers[child + 1])
                greater_child = child + 1;
        }
        if (greater_child != MAX)
        {
            std::swap(numbers[parent], numbers[greater_child]);
            parent = greater_child;
        }
        else 
            return;
    }
}
 
void heapsort::sift_up(std::vector<int>& numbers, std::size_t begin, std::size_t past_the_end, const int value)
{
    numbers[past_the_end - 1] = value;
    auto child = past_the_end - 1;
    while (child > 0)
    {
        auto parent = std::floor ((child - 1) / 2);
        if (numbers[parent] < numbers[child])
        {
            std::swap(numbers[parent], numbers[child]);
            child = parent;
        }
        else 
            return;
    }
} 

void heapsort::sort(std::vector<int> & numbers, std::size_t begin, std::size_t past_the_end)
{
    heapify(numbers, begin, past_the_end);
    auto right = past_the_end - 1;
    while (right > 0)
    {
        std::swap(numbers[right], numbers[begin]);
        sift_down(numbers, begin, right);
        right--;
    }
}

heapsort::~heapsort()
{
}

std::string heapsort::get_name() const 
{
    return std::string ("heapsort");
}

std::string heapsort::get_short_name() const
{
    return get_name();
}

