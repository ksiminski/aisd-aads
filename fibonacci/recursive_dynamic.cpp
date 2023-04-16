

#include <string>
#include <unordered_map>

#include "fibonacci.h" 
#include "recursive_dynamic.h"

std::size_t recursive_dynamic::value(const unsigned int n)
{
    if (not values.contains(n))
    {
        if (n < 2)
            values[n] = n;
        else 
            values[n] = value(n - 1) + value(n - 2);
    }
    return values[n];
}

 
std::string recursive_dynamic::get_name() const
{
    return "recursive dynamic";
}

std::string recursive_dynamic::get_short_name() const
{
    return "recdyn";
}

recursive_dynamic::~recursive_dynamic() 
{
}
 

