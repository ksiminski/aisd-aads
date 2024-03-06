
#ifndef GAPS_SHELL_H
#define GAPS_SHELL_H

#include <string>

#include "gap_generator.h"

class gaps_shell : public gap_generator
{

 public:
   gaps_shell ();
   gaps_shell (const gaps_shell & wzor);
   gaps_shell (gaps_shell && wzor);
   gaps_shell & operator= (const gaps_shell & wzor);
   gaps_shell & operator= (gaps_shell && wzor);
   virtual ~gaps_shell ();
 
    
protected:
    std::size_t divisor = 2;
    
public:
    std::string get_name() const override;
    std::string get_short_name() const override;
    
    
    std::size_t get_first_gap(const std::size_t N) override;
    std::size_t get_next_gap() override;
    
    std::shared_ptr<gap_generator> clone() const override;

};


#endif
