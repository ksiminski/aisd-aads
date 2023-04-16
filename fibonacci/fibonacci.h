

#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <string>

class fibonacci
{
public:
    virtual std::size_t value (const unsigned int n) = 0;
    virtual std::string get_name () const = 0; 
    virtual std::string get_short_name () const = 0;
    
};


#endif 
