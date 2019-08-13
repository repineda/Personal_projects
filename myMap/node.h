#ifndef NODE
#define NODE
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

template <typename Key, typename Value>
struct node
{
    Key key;
    Value value;
    node* next;
    node* previous;

    node(Key k = Key(), Value v = Value());
    node(const node<Key,Value> &other);
    ~node();
    void operator =(const node<Key,Value> &other);
    node* begin();
    node* end();
    bool operator ==(node<Key,Value> RHS);
    bool operator !=(const node<Key,Value> RHS);
    bool operator !=(const node<Key,Value> RHS)const;

    template <typename K, typename V>
    friend
    ostream& operator <<(ostream& out, node<K,V> & node);

    template <typename K, typename V>
    friend
    ostream& operator >>(ostream& in, node<K,V> & node);

};
template <typename Key, typename Value>
node<Key, Value>::node(Key k, Value v)
{
    key = k;
    value = v;
    next = NULL;
}

template <typename Key, typename Value>
node<Key, Value>::node(const node<Key,Value> &other)
{
    key = other.key;
    value = other.value;
    next = NULL;
}

template <typename Key, typename Value>
node<Key, Value>::~node()
{
    key = Key();
    value = Value();
    next = NULL;
}

template <typename Key, typename Value>
void node<Key, Value>:: operator =(const node<Key,Value> &other)
{
    if(this != &other)
    {
        key = other.key;
        value = other.value;
        next = NULL;
    }
}
template <typename Key, typename Value>
node<Key,Value>* node<Key, Value>::begin()
{
    return this;
}

template <typename Key, typename Value>
node<Key,Value>* node<Key, Value>::end()
{
    node<Key,Value>* endFinder = this;
    while (endFinder->next != NULL)
        endFinder = endFinder->next;
    return endFinder;
}
template <typename Key, typename Value>
bool node<Key,Value>::operator ==(node<Key,Value> RHS)
{
    if (key == RHS.key)
        return true;
    else
        return false;
}
template <typename Key, typename Value>
bool node<Key,Value>::operator !=(node<Key,Value> RHS)
{
    cout << "in != node operator" << endl;
    if (key != RHS.key)
        return true;
    else
        return false;
}
template <typename Key, typename Value>
bool node<Key,Value>::operator !=(const node<Key,Value> RHS)const
{
    cout << "in != node operator" << endl;
    if (key != RHS.key)
        return true;
    else
        return false;
}

template <typename K, typename V>
ostream& operator <<(ostream& out, const node<K,V> & node)
{
    if(out == cout)
    {
        out<< "[" << node.key << "] = "<< node.value;
    }
    else
    {
        out<<node.key<<"\a"<< node.value;
    }
    return out;
}


template <typename K, typename V>
ostream& operator >>(ostream& in, node<K,V> & node)
{
    if(in == cin)
    {
        cout <<"Key: ";
        cin>>node.key;
        cout<<"Value: ";
        cin>>node.value;
    }
    return in;
}

#endif // NODE

