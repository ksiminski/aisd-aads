

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <memory>

#include "../sorter.h"
#include "./pivots/pivot_selector.h"

class quicksort : public sorter
{
protected:
    std::shared_ptr<pivot_selector> pPivotSelector = nullptr;
    
public:
    quicksort (const pivot_selector & ps);
    quicksort (const quicksort & wzor);
    quicksort (quicksort && wzor);
    quicksort & operator= (const quicksort & wzor);
    quicksort & operator= (quicksort && wzor);
    
    virtual void sort (std::vector<int> & numbers, std::size_t begin, std::size_t part_the_end) override;
    virtual ~quicksort ();
    
    
    std::string get_name () const  override;
    std::string get_short_name() const  override;
    
};


#endif 
