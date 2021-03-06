#ifndef MYQUEUE_H
#define MYQUEUE_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "node.h"

using namespace std;


enum BASE_QUEUE_ERRORS{CANNOT_ADD_CAPACITY,EMPTY,FULL};

class myQueue
{
public:
    myQueue(unsigned int s = 5);
    ~myQueue();
    myQueue(const myQueue & other);
    myQueue& operator=(const myQueue &other);
    unsigned int capacity();
    unsigned int size();
    unsigned int moreCapacity(unsigned int s = 5);
    void swap(myQueue &other);
    bool full();
    bool empty();
    void *peek();
protected:
    myQueue& operator<<(node& n);
    myQueue& operator>>(node* &n);


private:
    node *head, *tail;
    unsigned int mySize, myCap;
    void copy(const myQueue &other);
    void nukem();
    void swap(node* &x, node* &y);
    void swap(unsigned int &x, unsigned int &y);
};

#endif // MYQUEUE_H
