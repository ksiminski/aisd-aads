

#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "../sorter.h"

class heapsort : public sorter
{
protected:
    void heapify (std::vector<int> & tab, std::size_t begin, std::size_t end);
    void sift_down (std::vector<int> & tab, std::size_t begin, std::size_t end);
    void sift_up (std::vector<int> & tab, std::size_t begin, std::size_t end, const int value);
    
    
public: 
    virtual void sort (std::vector<int> & numbers, std::size_t begin, std::size_t part_the_end) override;
    virtual ~heapsort ();
    
    std::string get_name() const override;
    std::string get_short_name() const override;
};


#endif 
