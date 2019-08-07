#ifndef TEMPLATENODE_H
#define TEMPLATENODE_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "node.h"

using namespace std;
enum NODE_TYPE{REGULAR, PRIORITY};

template <typename DATA, typename PRIORITY>
class tNode : public node
{
public:
    tNode(NODE_TYPE = REGULAR);
    ~tNode();
    tNode(const tNode<DATA,PRIORITY> &other);
    tNode<DATA,PRIORITY>& operator=(tNode<DATA,PRIORITY> &other);
    DATA getData();
    void setData(const DATA &d);
    void setPriority(const PRIORITY &p);

    template<typename T, typename U>
    friend
    ostream& operator<<(ostream & out, const tNode<T,U> &n);
    template<typename T, typename U>
    friend
    istream& operator>>(istream & out, const tNode<T,U> &n);

    template<typename T, typename U>
    bool operator>(tNode<T,U> &x, tNode<T,U> &y);
private:

};
tNode(NODE_TYPE = REGULAR);
~tNode();
tNode(const tNode<DATA,PRIORITY> &other);
tNode<DATA,PRIORITY>& operator=(tNode<DATA,PRIORITY> &other);
DATA getData();
void setData(const DATA &d);
void setPriority(const PRIORITY &p);

template<typename T, typename U>
ostream& operator<<(ostream & out, const tNode<T,U> &n);
template<typename T, typename U>
istream& operator>>(istream & out, tNode<T,U> &n);

#endif // TEMPLATENODE_H
