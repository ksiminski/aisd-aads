
#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#include <vector>
#include <unordered_map>
#include <memory>
#include <map>
#include <initializer_list>

namespace ksi
{
    /** Template class for disjoint set data structure
     @date 2020-08-08
     @author Krzysztof Siminski
     */
    template <class T>
    class disjoint_set 
    { 
        struct item
        {
            T value;
            std::size_t rank;
            std::shared_ptr<item> pRepresentative;
        };
        
        std::unordered_map<T, std::shared_ptr<item>> items;
        
    public:
        disjoint_set () {}
        /** Constructor makes disjoint sets for all items in the initializer list. */
        disjoint_set(const std::initializer_list<T> & wholeset)
        {
            //std::size_t rank = 0;
            for (auto & i : wholeset) 
            {
                push_back(i);
            }      
        }
        
    public:
        disjoint_set (const disjoint_set & wzor)
        {
            items = wzor.items;
        }
        
    public:
        disjoint_set (disjoint_set && wzor)
        {
            std::swap(items, wzor.items);
        }
        
    public:
        void push_back (const T & t)
        {
            std::shared_ptr<item> pNew (new item{t, 0, nullptr});
            pNew->pRepresentative = pNew;
            items[t] = pNew;
        }
        
    private:
        /** @return The method returns an address of the representative of an item.
         @remark The method uses the compress path technique. */
        std::shared_ptr<item> FindRepresentative(const T & l) 
        { 
            if (items.at(l)->pRepresentative->value == l) 
                return items[l]->pRepresentative;
            return items[l]->pRepresentative = FindRepresentative(items[l]->pRepresentative->value);
        }
        
        /** @return The method returns an address of the representative of an item.
         @remark The method does not use the compress path technique. */
     public:
         T DirectRepresentative (const T & l)
         {
             return items[l]->pRepresentative->value;           
         }
        
    public:
        /** @return The method returns the value of the representive. */
        T Find (const T & l)
        {
            return FindRepresentative(l)->value;           
        }
            
    public:
        /** The method merges sets holding two items. 
         *  If the items are elements of the same 
         *  set, nothing is done.  */
        void Union(const T & a, const T & b) 
        { 
            auto px = FindRepresentative(a);
            auto py = FindRepresentative(b);
            
            if (px == py)
                return;
            
            if (px->rank < py->rank)
                px->pRepresentative = py;
            else if (px->rank > py->rank)
                py->pRepresentative = px;
            else
            {
                px->pRepresentative = py;
                py->rank++;
            }
        }
        
    public:
        /** @return The method returns values of representatives and item 
         * they are representatives of. The key of the map is a representative. 
         * The vector in the map is a vector of items represented by 
         * the key--representative. */
        std::map<T, std::vector<T>> getSets ()
        {
            std::map<T, std::vector<T>> sets;
            
            for (const auto & it : items)
            {
                auto p = FindRepresentative(it.second->value);
                sets[p->value].push_back(it.second->value);
            }
            return sets;
        }
    };
}

#endif

