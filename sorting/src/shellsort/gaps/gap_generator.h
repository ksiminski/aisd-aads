
#ifndef GAP_GENERATOR_H
#define GAP_GENERATOR_H

#include <string>
#include <memory>

class gap_generator
{
 public:
   gap_generator ();
   gap_generator (const gap_generator & wzor);
   gap_generator (gap_generator && wzor);
   gap_generator & operator= (const gap_generator & wzor);
   gap_generator & operator= (gap_generator && wzor);
   virtual ~gap_generator ();
   
 
   
protected:
    std::size_t _N;    
      
public:
   virtual std::string get_name () const = 0;
   virtual std::string get_short_name () const = 0;
      
   virtual std::size_t get_first_gap(const std::size_t N) = 0;
   virtual std::size_t get_next_gap() = 0;
   
   virtual std::shared_ptr<gap_generator> clone() const = 0;
   
};


#endif
