

#ifndef SHELLSORT_H
#define SHELLSORT_H


#include <memory>

#include "../sorter.h"
#include "./gaps/gap_generator.h"

class shellsort : public sorter
{
public: 
    virtual void sort (std::vector<int> & numbers, std::size_t begin, std::size_t part_the_end) override;
    virtual ~shellsort ();
    
    shellsort(const gap_generator & gap);
    shellsort (const shellsort & wzor);
    shellsort (shellsort && wzor);
    shellsort & operator= (const shellsort & wzor);
    shellsort & operator= (shellsort && wzor);
    
    
    std::string get_name () const override;
    std::string get_short_name() const override;
    
protected:
    std::shared_ptr<gap_generator> pGaps = nullptr;
};


#endif 
