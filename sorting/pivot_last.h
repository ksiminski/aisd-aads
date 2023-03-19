
#ifndef PIVOT_LAST_H
#define PIVOT_LAST_H

#include "pivot_selector.h"

class pivot_last : public pivot_selector
{
 public:
   pivot_last ();
   pivot_last (const pivot_last & wzor);
   pivot_last (pivot_last && wzor);
   pivot_last & operator= (const pivot_last & wzor);
   pivot_last & operator= (pivot_last && wzor);
   virtual ~pivot_last ();
   
   int get_pivot(const std::vector<int> & array, const std::size_t first, const std::size_t past_the_last) override;
   std::shared_ptr<pivot_selector> clone() const override;
   
   std::string get_name() const override;
   std::string get_short_name() const override;
};


#endif
