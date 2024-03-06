
#ifndef GAPS_FRANK_H
#define GAPS_FRANK_H

#include "gap_generator.h"

class gaps_frank : public gap_generator
{
 public:
   gaps_frank ();
   gaps_frank (const gaps_frank & wzor);
   gaps_frank (gaps_frank && wzor);
   gaps_frank & operator= (const gaps_frank & wzor);
   gaps_frank & operator= (gaps_frank && wzor);
   virtual ~gaps_frank ();
   
   private:
    const std::string name {"Frank"};
    
protected:
    protected:
    std::size_t mianownik = 4;
    
public:
    std::string get_name() const override;
    std::string get_short_name() const override;
    
    
    std::size_t get_first_gap(const std::size_t N) override;
    std::size_t get_next_gap() override;
    
    std::shared_ptr<gap_generator> clone() const override;
    
    
};


#endif
