

#ifndef MERGESORT_H
#define MERGESORT_H

#include "sorter.h"

class mergesort : public sorter
{
public: 
    virtual void sort (std::vector<int> & array, std::size_t begin, std::size_t end) override;
    virtual ~mergesort ();
    
    std::string get_name() const override; 
    std::string get_short_name() const override;
};


#endif 
