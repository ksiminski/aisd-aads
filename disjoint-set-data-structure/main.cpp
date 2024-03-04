
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
 
#include "disjoint_set.h" 

#define debug(x) std::cout << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl

 
 

template <class T>
void print(std::initializer_list<int> const & universe, ksi::disjoint_set<T> & dis) 
{
   for (const auto & i : universe)
   std::cout << i << " --> " <<  dis.Find(i) << std::endl;
//       std::cout << i << " --> " <<  dis.DirectRepresentative(i) << std::endl;       
}

int main() 
{
    try 
    {
        std::initializer_list<int> wholeset = { 1,2,3,4,5,6,7,8,9 }; // items of whole set
        ksi::disjoint_set<int> dis {wholeset}; 
        
    
        print(wholeset, dis);
        std::cout << "------------" << std::endl;
        
        dis.Union(1,2);
        print(wholeset, dis);
        std::cout << "------------" << std::endl;
        
        dis.Union(3,4);
        print(wholeset, dis);
        std::cout << "------------" << std::endl;
        
        dis.Union(5,6);
        print(wholeset, dis);
        std::cout << "------------" << std::endl;
        
        dis.Union(7,8);
        print(wholeset, dis);
        std::cout << "------------" << std::endl;
        
        dis.Union(1,3);
        print(wholeset, dis);
        std::cout << "------------" << std::endl;
        
        dis.Union(5,8);
        print(wholeset, dis);
        std::cout << "------------" << std::endl;
        
        dis.Union(1,8);
        print(wholeset, dis);
        std::cout << "------------" << std::endl;
        
        std::cout << dis.Find(1) << std::endl;
        
        print(wholeset, dis);
        std::cout << "------------" << std::endl;
        
        dis.Union(7, 6);
        if (dis.Find(7) == dis.Find(6)) // if they are belong to same set or not.
            std::cout<<"Yes"<<std::endl;
        else
            std::cout<<"No"<<std::endl;
        
        debug(dis.Find(7));
        debug(dis.Find(6));
        
        if (dis.Find(3) == dis.Find(4))
            std::cout<<"Yes"<<std::endl;
        else
            std::cout<<"No"<<std::endl;
        
    }
    catch (std::exception & ex)
    {
        std::cerr << ex.what() << std::endl;
    }
   return 0;
   
}

