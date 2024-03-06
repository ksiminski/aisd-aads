
#include "gap_generator.h"

gap_generator::gap_generator ()
{
}

gap_generator::~gap_generator ()
{
   // delete what is to delete

}

gap_generator::gap_generator (const gap_generator & wzor)
{
   // copy what is to copy

}

gap_generator & gap_generator::operator= (const gap_generator & wzor)
{
   if (this == & wzor)
      return *this;


   // remove what is to remove

   // allocate what is to allocate

   return *this;
}

gap_generator::gap_generator (gap_generator && wzor)
{
   // swap what is to swap

}

gap_generator & gap_generator::operator= (gap_generator && wzor)
{
   if (this == & wzor)
      return *this;


   // swap what is to swap

   return *this;
}

 
