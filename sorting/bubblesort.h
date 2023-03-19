

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "sorter.h"

class bubblesort : public sorter
{
public: 
    virtual void sort (std::vector<int> & numbers, std::size_t begin, std::size_t part_the_end) override;
    virtual ~bubblesort ();
    
    std::string get_name ()  const override;
    std::string get_short_name()  const override;
};


#endif 
