
#ifndef PIVOT_RANDOM_H
#define PIVOT_RANDOM_H

#include <random>
#include <chrono>

#include "pivot_selector.h"

class pivot_random : public pivot_selector
{
protected:
   std::default_random_engine engine; 
 public:
   pivot_random ();
   pivot_random (const pivot_random & wzor);
   pivot_random (pivot_random && wzor);
   pivot_random & operator= (const pivot_random & wzor);
   pivot_random & operator= (pivot_random && wzor);
   virtual ~pivot_random ();
   
   int get_pivot(const std::vector<int> & array, const std::size_t first, const std::size_t past_the_last) override;
   std::shared_ptr<pivot_selector> clone() const override;
   
   std::string get_name() const override;
   std::string get_short_name() const override;
};


#endif
