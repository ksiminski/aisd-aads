

#ifndef ITERATIVE_DYNAMIC_H
#define ITERATIVE_DYNAMIC_H

#include <unordered_map>

#include "fibonacci.h"

/** 
 [PL] Klasa implementuje metode wyznaczajaca liczby Fibonacciego z wykorzystaniem
      programowania dynamicznego. Jest to funkcja iteracyjna. Zapamietuje dwie 
      poprzednie wartosci, zeby wyznaczyc biezaca.
 [EN] The class implements a method for Fibonacci numbers with the dynamic 
      programming approach. It is an interative function. It saves two previous
      values for elaborating the current one.
 */
class iterative_dynamic : public fibonacci
{

public: 
    virtual std::size_t value (const unsigned int n) override;
    virtual ~iterative_dynamic ();
     
    iterative_dynamic () = default;
    iterative_dynamic (const iterative_dynamic & wzor) = default;
    iterative_dynamic (iterative_dynamic && wzor) = default;
    iterative_dynamic & operator= (const iterative_dynamic & wzor) = default;
    iterative_dynamic & operator= (iterative_dynamic && wzor) = default;
    
    std::string get_name () const override;
    std::string get_short_name() const override;

};


#endif 
