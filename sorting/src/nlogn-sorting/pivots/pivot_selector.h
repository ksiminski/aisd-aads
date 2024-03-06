
#ifndef PIVOT_SELECTOR_H
#define PIVOT_SELECTOR_H

#include <vector>
#include <memory>
#include <string>

class pivot_selector
{
 public:
   pivot_selector ();
   pivot_selector (const pivot_selector & wzor);
   pivot_selector (pivot_selector && wzor);
   pivot_selector & operator= (const pivot_selector & wzor);
   pivot_selector & operator= (pivot_selector && wzor);
   virtual ~pivot_selector ();
   
   virtual int get_pivot(const std::vector<int> & array, const std::size_t first, const std::size_t past_the_last) = 0;
   
   virtual std::shared_ptr<pivot_selector> clone () const = 0;
   
   virtual std::string get_name() const = 0;
   virtual std::string get_short_name() const = 0;
   
   
};


#endif
