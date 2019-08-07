#ifndef NODE_H
#define NODE_H
#include <cstdlib>

using namespace std;

class node
{
protected:
    void *data ,*priority;
    //unsigned int priority; // 100% correctly then void* so that priority could be class
    node *next;

public:
    node();
    ~node();

    node* getNext();
    void setNext(node* n);
    void* getDataPtr();
    void setDataPtr(void *d);
    void* getPriorityPtr();
    void setPriorityPtr(void *p);

};

#endif // NODE_H
