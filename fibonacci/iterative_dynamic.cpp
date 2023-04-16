

#include <string>
#include <unordered_map>

#include "fibonacci.h" 
#include "iterative_dynamic.h"

std::size_t iterative_dynamic::value(const unsigned int n)
{
    if (n < 2) 
        return n;
    std::size_t previous {0};  // F(0) = 0
    std::size_t current {1};   // F(1) = 1
    std::size_t result {0};
    
    for (int i = 2; i <= n; i++)
    {
        result = previous + current;
        previous = current;
        current = result;
    }
    return current;
}

 
std::string iterative_dynamic::get_name() const
{
    return "iterative dynamic";
}

std::string iterative_dynamic::get_short_name() const
{
    return "iterdyn";
}

iterative_dynamic::~iterative_dynamic() 
{
}
 

