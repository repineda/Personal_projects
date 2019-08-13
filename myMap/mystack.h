#ifndef MYSTACK
#define MYSTACK\

#include <iostream>
#include<cstdlib>

using namespace std;

enum STACK_ERRORS {STACK_FULL, STACK_EMPTY};

template<typename T>
class myStack
{
public:
    myStack(int s = 5, int c = 1<<29);
    ~myStack();
    myStack(const myStack<T>& other);
    myStack<T>& operator=(const myStack<T> &other);
    void push(const T &data);
    T pop();
    T peak();
    bool empty();
    bool full();
    int size();
    int capacity();
    void clear();
    void swap(myStack<T> &other);

    template<typename T>
    friend
    ostream& operator<<(ostream &out, const myStack<U> &s);
    template<typename T>
    friend
    ostream& operator>>(istream &out, const myStack<U> &s);
private:
    T* stack;
    int msize, cap;
    void copy(const myStack<T> &other);

};
template<typename T>
myStack<T>::myStack<T>(int s = 5, int c = 1<<29)
{

}
template<typename T>
myStack<T>::~myStack(){

}

template<typename T>
myStack<T>::myStack(const myStack<T>& other)
{

}

template<typename T>
myStack<T>::myStack<T>& operator=(const myStack<T> &other)
{

}

template<typename T>
void myStack<T>::push(const T &data)
{

}

template<typename T>
T myStack<T>::pop()
{

}

template<typename T>
T myStack<T>::peak()
{

}

template<typename T>
bool myStack<T>::empty()
{

}

template<typename T>
bool myStack<T>::full()
{

}

template<typename T>
int myStack<T>::size()
{

}

template<typename T>
int myStack<T>::capacity()
{

}

template<typename T>
void myStack<T>::clear()
{

}

template<typename T>
void myStack<T>::swap(myStack<T> &other)
{

}

template<typename U>
friend
ostream& operator<<(ostream &out, const myStack<U> &s);
template<typename U>
friend
ostream& operator>>(istream &out, const myStack<U> &s);

#endif // MYSTACK

