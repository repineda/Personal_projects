#include "myqueue.h"


myQueue::myQueue(unsigned int s)
{

}

myQueue::~myQueue()
{
    nukem();
}

myQueue::myQueue(const myQueue & other)
{
    if(this != &other)
    {
        nukem();
        this->myCap = other.myCap;
        this->head = other.head;
        this->tail = other.tail;
        this->mySize = other.mySize;
    }
}

myQueue& myQueue::operator=(const myQueue &other)
{
    this->myCap = other.myCap;
    this->head = other.head;
    this->tail = other.tail;
    this->mySize = other.mySize;
    return *this;
}

unsigned int myQueue::capacity()
{
    return myCap;
}

unsigned int myQueue::size()
{
    return mySize;
}

unsigned int myQueue::moreCapacity(unsigned int s)
{
    if(s < myCap)
    {
        throw CANNOT_ADD_CAPACITY;
    }
    myCap = s;
    return s;
}

void myQueue::swap(myQueue &other)
{
    swap(mySize, other.mySize);//copy swap it now function here this is for unsigned ints
    swap(myCap,other.myCap);
    swap(head,other.head);// swap for pointers
    swap(tail,other.tail);

}
void myQueue::swap(node* &x, node* &y)
{
    node* temp = x;
    x=y;
    y=temp;
}

void myQueue::swap(unsigned int &x, unsigned int &y)
{
    unsigned int temp = x;
    x=y;
    y=temp;
}

bool myQueue::full()
{
    return myCap == mySize;
}

bool myQueue::empty()
{
    return !head;
}

void* myQueue::peek()
{
    if(!empty())
    {
        throw EMPTY;
    }
    return head->getDataPtr();
}

myQueue& myQueue::operator<<(node& n)
{
    if(full())
    {
        throw FULL;
    }
    tail->setNext(&n);
    tail = &n;
    ++mySize;
    return *this;
}

myQueue& myQueue::operator>>(node* &n)
{
    if(empty())
    {
        throw EMPTY;
    }
    n = head;
    head->setNext(head->getNext());
    return *this;

}

void myQueue::nukem()
{
    this->head = NULL;
    this->tail = NULL;
    this->myCap = 0;
    this->mySize = 0;
}
