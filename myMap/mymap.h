#ifndef MYMAP_H
#define MYMAP_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "node.h"

using namespace std;

#define unsigned int size_t

enum myMapErrors {DUPLICATE_KEY,EMPTY,FULL};

template<typename Key, typename Value>
class myMap
{
public:
    template<class Container>
    class iterator
    {
    public:
       iterator()
       {
           ptr = NULL;
        }
       iterator(node<Key,Value>* P)
       {
           ptr = P;
       }

       ~iterator()
       {

       }

       //overloads ++ operator for iterator
       void operator ++()
       {
           ptr = ptr->next;
       }
       node<Key, Value> operator *()
       {
           if (ptr == NULL)
               return ptr;
           else
               return ptr;
       }
       bool operator !=(iterator RHS)
       {
           if (ptr != RHS.ptr)
               return true;
           else
               return false;
       }


       auto begin(Container& cont)->decltype(cont.begin());
       auto end(Container& cont)->decltype(cont.end());


   // private:
       node<Key,Value> *ptr;
    };
    template<class Container>
    class const_iterator
    {
    public:
       const_iterator()
       {
           ptr = NULL;
       }

       const_iterator(node<Key,Value>* P)
       {
           ptr = P;
       }

       ~const_iterator()
       {

       }

       //overloads ++ operator for iterator
       void operator ++()
       {
           ptr = ptr->next;
       }
       const node<Key, Value> operator *()
       {
           if (ptr == NULL)
               return ptr;
           else
               return ptr;
       }
       bool operator !=(const_iterator RHS)
       {
           if (ptr != RHS.ptr)
               return true;
           else
               return false;
       }

       auto begin(Container& cont)->decltype(cont.begin());
       auto end(Container& cont)->decltype(cont.end());


   // private:
       node<Key,Value> *ptr;
    };

    explicit myMap();
    explicit myMap(const Key &k, const Value &v);
    explicit myMap(const myMap<Key,Value> &other);
    myMap<Key,Value>& operator=(const myMap<Key,Value> &other);
    ~myMap();
    /*
         * map['this'] = 'that'; LHS call
         * word = map['this']; => RHS call
         */

    //Capacity functions
    bool empty();
    int size();
    int max_size();

    //Element access
    Value& at(const Key &k);
    Value& operator[](const Key &k);
    Value& operator[](const Key &k) const;

    //Modifiers
    void insert(const Key &k, const Value &v);
    void erase(iterator<node<Key, Value> > position);
    void erase(const Key& k);
    void erase(iterator<node<Key, Value> > first, iterator<node<Key, Value> > last);
    void swap (myMap<Key,Value> &x);
    void clear();
    void emplace(const Key &k, const Value &v);

    //Operations
    iterator<node<Key, Value> > find (const Key& k);
    const_iterator<node<Key, Value> > find (const Key& k) const;
    bool count(const Key& k) const;
    iterator<node<Key, Value> > lower_bound (const Key& k);
    const_iterator<node<Key, Value> > lower_bound (const Key& k) const;
    iterator<node<Key, Value> > upper_bound (const Key& k);
    const_iterator<node<Key, Value> > upper_bound (const Key& k) const;

    template<typename T, typename U>
    friend
    ostream& operator<<(ostream &out, const myMap<T,U> &map);

    template<typename T, typename U>
    friend
    istream& operator>>(istream &in, myMap<T,U> &map);

private:
    node<Key,Value> *first;
    size_t qty, maxSize;
    void copy(const myMap<Key,Value> &other);
    void nukem();
    node<Key,Value>* begin();
    node<Key,Value>* end();
};
//*********************************************


template<typename Key, typename Value>
myMap<Key,Value>::myMap()
{
    qty = 0;
    maxSize = 1 << 29;
    first = NULL;
}

template<typename Key, typename Value>
myMap<Key,Value>::myMap(const Key &k, const Value &v)
{
    first = new node<Key,Value>(k,v);
    qty = 1;
    maxSize = 1 << 29;
}

template<typename Key, typename Value>
myMap<Key,Value>::myMap(const myMap<Key,Value> &other)
{
    copy(other);
}

template<typename Key, typename Value>
myMap<Key,Value>& myMap<Key,Value>::operator=(const myMap<Key,Value> &other)
{
    if(this != &other)
    {
        nukem();
        copy(other);
    }
    return *this;
}

template<typename Key, typename Value>
myMap<Key,Value>::~myMap()
{

}

/*
 * map['this'] = 'that'; LHS call
 * word = map['this']; => RHS call
 */

//Capacity functions

template<typename Key, typename Value>
bool myMap<Key,Value>::empty()
{
    return !first;
}

template<typename Key, typename Value>
int myMap<Key,Value>::size()
{
    return qty;
}

template<typename Key, typename Value>
int myMap<Key,Value>::max_size()
{
    return maxSize;
}


//Element access

template<typename Key, typename Value>
Value& myMap<Key,Value>::at(const Key &k)
{
    iterator<node<Key,Value> > it = this->find(k);
    return it.ptr->value;
}

template<typename Key, typename Value>
Value& myMap<Key,Value>::operator[](const Key &k)
{
    return this->at(k);
}

template<typename Key, typename Value>
Value& myMap<Key,Value>::operator[](const Key &k) const
{
    return this->at(k);
}

//Modifiers

template<typename Key, typename Value>
void myMap<Key,Value>::insert(const Key &k, const Value &v)
{
    if(first == NULL)
    {
        first = new node<Key,Value>(k,v);
    }
    node<Key,Value> anchor;
    anchor.next = first;
    node<Key,Value> *ptr = &anchor;
    for(;ptr->next && k < ptr->next->key; ptr = ptr->next)
    {
        if(k==ptr->next->key)//if it exist already throw dup
            throw DUPLICATE_KEY;
        if(!ptr->next)
        {
            cout << "NEW NODE ATTACHED TO END" << endl;
            ptr->next = new node<Key,Value>(k,v);
        }
        else
        {
            node<Key,Value>* newNode = new node<Key,Value>(k,v);
            newNode->next = ptr->next;
            ptr->next = newNode;
            first = anchor.next;
            break;
        }
    }
}

template<typename Key, typename Value>
void myMap<Key,Value>::erase(iterator<node<Key, Value> > position)
{
    iterator<node<Key, Value> > it(first);
    while(it.ptr != position.ptr)
    {
        ++it;
    }
    it.ptr->next = position.ptr->next;
}

template<typename Key, typename Value>
void myMap<Key,Value>::erase(const Key& k)
{
    iterator<node<Key, Value> > it = find(k);
    erase(it);
}

template<typename Key, typename Value>
void myMap<Key,Value>::erase(iterator<node<Key, Value> > first, iterator<node<Key, Value> > last)
{
    for(iterator<node<Key,Value> > it = first; it!= last; ++it)
    {
        erase(it);
    }
}

template<typename Key, typename Value>
void myMap<Key,Value>::swap (myMap<Key,Value> &other)
{
    swapItNow(first, other.first);
    swapItNow(qty, other.qty);
    swapItNow(maxSize,other.maxSize);
}

template<typename Key, typename Value>
void myMap<Key,Value>::clear()
{
    nukem();
}

template<typename Key, typename Value>
void myMap<Key,Value>::emplace(const Key &k, const Value &v)
{
    insert(k,v);
}

//Operations

template<typename Key, typename Value>
myMap<Key,Value>::iterator<node<Key, Value> > myMap<Key,Value>::find (const Key& k)
{
    iterator<node<Key, Value> > it(first);
    while(it.ptr->next != end() )
    {
        if(it.ptr->key == k)
            return it;
        ++it;
    }
    return it;
}

template<typename Key, typename Value>
myMap<Key,Value>::const_iterator<node<Key, Value> > myMap<Key,Value>::find (const Key& k) const
{
    const_iterator<node<Key, Value> > it(first);
    while(!it.ptr->next )
    {
        if(it.ptr->key == k)
            return it;
        ++it;
    }
    cout << "after while loop" << endl;
    return it;
}

template<typename Key, typename Value>
bool myMap<Key,Value>::count(const Key& k) const
{
    iterator<node<Key, Value> > it(first);
    if(find(k).ptr != it.ptr->end())
    {
        return 1;
    }
    return 0;
}

template<typename Key, typename Value>
myMap<Key,Value>::iterator<node<Key, Value> > myMap<Key,Value>::lower_bound (const Key& k)
{
    iterator<node<Key,Value> > it = find(k);
    ++it;
    return it;
}

template<typename Key, typename Value>
myMap<Key,Value>::const_iterator<node<Key, Value> > myMap<Key,Value>::lower_bound (const Key& k) const
{
    iterator<node<Key,Value> > it = find(k);
    it++;
    return it;
}

template<typename Key, typename Value>
myMap<Key,Value>::iterator<node<Key, Value> > myMap<Key,Value>::upper_bound (const Key& k)
{
    iterator<node<Key, Value> > it = first;
    while(it.ptr->next != find(k).ptr)
    {
        it++;
    }
    return it;
}

template<typename Key, typename Value>
myMap<Key,Value>::const_iterator<node<Key, Value> > myMap<Key,Value>::upper_bound (const Key& k) const
{
    const_iterator<node<Key, Value> > it = first;
    while(it.ptr->next != find(k).ptr)
    {
        it++;
    }
    return it;
}

template<typename Key, typename Value>
void myMap<Key,Value>::copy(const myMap<Key,Value> &other)
{
    node<Key,Value> *me, *you;
    qty = other.qty;
    maxSize = other.maxSize;
    if(qty)
    {
        first = new node<Key,Value>(other.first);
        me = first;
        you = other.first;
        for(;you != NULL; you = you->next, me = me->next)
        {
            me->next = new node<Key,Value>(you->next);
        }
    }
}

template<typename Key, typename Value>
void myMap<Key,Value>::nukem()
{
    qty = 0;
    for(node<Key,Value> *ptr = first; ptr != NULL; ptr = first)
    {
        first = first->next;
        delete ptr;
    }
}
template<typename Key, typename Value>
node<Key,Value>*  myMap<Key,Value>::begin()
{
    return first;
}

template<typename Key, typename Value>
node<Key,Value>*  myMap<Key,Value>::end()
{
    return NULL;
}

template<typename T, typename U>
ostream& operator<<(ostream &out, const myMap<T,U> &map)
{
//    if(&out == &cout)
//    {
//        out<<"[" <<map;
//    }
    for(node <T,U>  it = map.begin(); it!= map.end(); ++it)
    {
        out<<*it<<endl;
    }
    return out;
}

template<typename T, typename U>
istream& operator>>(istream &in, myMap<T,U> &map)
{
    node<T,U> input;
    while(in>>input)
    {
        map.insert(input.key,input.value);
    }
    return in;
}
template<typename A>
void swapItNow(A&z, A&y)
{
    A temp = z;
    z = y;
    y = temp;
}

#endif // MYMAP_H

