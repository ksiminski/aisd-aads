
#ifndef PIVOT_FIRST_H
#define PIVOT_FIRST_H

#include "pivot_selector.h"

class pivot_first : public pivot_selector
{
 public:
   pivot_first ();
   pivot_first (const pivot_first & wzor);
   pivot_first (pivot_first && wzor);
   pivot_first & operator= (const pivot_first & wzor);
   pivot_first & operator= (pivot_first && wzor);
   virtual ~pivot_first ();
   
   int get_pivot(const std::vector<int> & array, const std::size_t first, const std::size_t past_the_last) override;
   std::shared_ptr<pivot_selector> clone() const override;
   
   std::string get_name() const override;
   std::string get_short_name() const override;
};


#endif
