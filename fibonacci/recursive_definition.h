

#ifndef RECURSIVE_DEFINITION_H
#define RECURSIVE_DEFINITION_H

#include <memory>

#include "fibonacci.h"

/** 
 [PL] Klasa implementuje metode wyznaczajaca liczby Fibonacciego z definicji. 
      Jest to funkcja rekurencyjna. 
 [EN] The class implements a method for Fibonacci numbers by definition.
      It is a recursive function.
 */
class recursive_definition : public fibonacci
{
public: 
    virtual std::size_t value (const unsigned int n) override;
    virtual ~recursive_definition ();
     
    recursive_definition () = default;
    recursive_definition (const recursive_definition & wzor) = default;
    recursive_definition (recursive_definition && wzor) = default;
    recursive_definition & operator= (const recursive_definition & wzor) = default;
    recursive_definition & operator= (recursive_definition && wzor) = default;
    
    std::string get_name () const override;
    std::string get_short_name() const override;

};


#endif 
