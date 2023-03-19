
#ifndef PIVOT_MIDDLE_H
#define PIVOT_MIDDLE_H

#include "pivot_selector.h"

class pivot_middle : public pivot_selector
{
 public:
   pivot_middle ();
   pivot_middle (const pivot_middle & wzor);
   pivot_middle (pivot_middle && wzor);
   pivot_middle & operator= (const pivot_middle & wzor);
   pivot_middle & operator= (pivot_middle && wzor);
   virtual ~pivot_middle ();
   
   int get_pivot(const std::vector<int> & array, const std::size_t first, const std::size_t past_the_last) override;
   std::shared_ptr<pivot_selector> clone() const override;
   
   std::string get_name() const override;
   std::string get_short_name() const override;
};


#endif
