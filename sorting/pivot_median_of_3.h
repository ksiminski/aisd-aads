
#ifndef PIVOT_MEDIAN_OF_3_H
#define PIVOT_MEDIAN_OF_3_H

#include "pivot_random.h"

class pivot_median_of_3 : public pivot_random
{
 public:
   pivot_median_of_3 ();
   pivot_median_of_3 (const pivot_median_of_3 & wzor);
   pivot_median_of_3 (pivot_median_of_3 && wzor);
   pivot_median_of_3 & operator= (const pivot_median_of_3 & wzor);
   pivot_median_of_3 & operator= (pivot_median_of_3 && wzor);
   virtual ~pivot_median_of_3 ();
   
   int get_pivot(const std::vector<int> & array, const std::size_t first, const std::size_t past_the_last) override;
   std::shared_ptr<pivot_selector> clone() const override;
   
   std::string get_name() const override;
   std::string get_short_name() const override;
   
protected:
   int median (const int _1, const int _2, const int _3);
   
};


#endif
