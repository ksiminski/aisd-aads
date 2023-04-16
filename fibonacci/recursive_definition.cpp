

#include <string>
#include "fibonacci.h" 
#include "recursive_definition.h"

std::size_t recursive_definition::value(const unsigned int n)
{
    if (n < 2)
        return n;
    else 
        return value(n - 1) + value (n - 2);
}

 
std::string recursive_definition::get_name() const
{
    return "recursive definition";
}

std::string recursive_definition::get_short_name() const
{
    return "recdef";
}

recursive_definition::~recursive_definition() 
{
}
 

