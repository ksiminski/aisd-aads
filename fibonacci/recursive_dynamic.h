

#ifndef RECURSIVE_DYNAMIC_H
#define RECURSIVE_DYNAMIC_H

#include <unordered_map>

#include "fibonacci.h"


/** 
 [PL] Klasa implementuje metode wyznaczajaca liczby Fibonacciego z wykorzystaniem
      programowania dynamicznego. Jest to funkcja rekurencyjna, ale sprawdza,
      czy wartosc nie zostala juz wyznaczona. Jezeli tak, to odczytuje te wartosc
      z tablicy zamiast wyznaczac ja na od poczatku.
 [EN] The class implements a method for Fibonacci numbers with the dynamic 
      programming approach. It is a recursive function, but it checks if a value
      has been elaborated. If yes, the value is taken from an array instead 
      of elaborating it from the scratch.
 */
class recursive_dynamic : public fibonacci
{
protected :
    std::unordered_map<int, std::size_t> values;  // hash-table, O(1) 
public: 
    virtual std::size_t value (const unsigned int n) override;
    virtual ~recursive_dynamic ();
     
    recursive_dynamic () = default;
    recursive_dynamic (const recursive_dynamic & wzor) = default;
    recursive_dynamic (recursive_dynamic && wzor) = default;
    recursive_dynamic & operator= (const recursive_dynamic & wzor) = default;
    recursive_dynamic & operator= (recursive_dynamic && wzor) = default;
    
    std::string get_name () const override;
    std::string get_short_name() const override;

};


#endif 
