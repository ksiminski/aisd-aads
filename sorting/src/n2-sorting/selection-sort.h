

#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "../sorter.h"

class selection_sort : public sorter
{
public: 
    virtual void sort (std::vector<int> & numbers, std::size_t begin, std::size_t part_the_end) override;
    virtual ~selection_sort ();
    
    std::string get_name ()  const override;
    std::string get_short_name()  const override;
};


#endif 
