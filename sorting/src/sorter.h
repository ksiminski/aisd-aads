

#ifndef SORTER_H
#define SORTER_H

#include <vector>
#include <string>

class sorter 
{
public:
    virtual void sort (std::vector<int> & numbers, std::size_t begin, std::size_t end) = 0;
    virtual std::string get_name () const = 0; 
    virtual std::string get_short_name () const = 0;
    
};


#endif 
