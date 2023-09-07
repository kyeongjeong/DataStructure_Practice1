#include <iostream>
using namespace std;

template <class T>
class ChainNode {

    template <class U> friend class Chain;

public:
    ChainNode(const T data, ChainNode<T>* link = NULL);

private:
    T data;
    ChainNode<T>* link;
};

template <class T>
class Chain {
public:
    Chain(void);
    virtual ~Chain();
    bool IsEmpty(void);
    void StackPush(T data);
    void StackPop(void);
    void QueuePush(T data);
    void QueuePop(void);
    void Print(void);
private:
    ChainNode<T>* first;
    ChainNode<T>* last;
};

template <class T>
ChainNode<T>::ChainNode(const T data, ChainNode<T>* link) {

    this->data = data;
    this->link = link; 
}

template <class T>
Chain<T>::Chain(void) {

    first = NULL;
    last = NULL;
}

template <class T>
Chain<T>::~Chain() {

    ChainNode<T>* next = NULL;

    while(first != NULL) {

        next = first->link;
        cout << "Delete: " << first->data << endl;
        delete first;
        first = next;
    }
}

template <class T>
bool Chain<T>::IsEmpty(void) {
    
    return (first == NULL);
}

template <class T>
void Chain<T>::Print(void) {

    ChainNode<T>* current = first;

    cout << "Print: " << first->data << endl;
    while(current != NULL) {

        cout << current->data << " ";
        current = current->link;
    }
    cout << endl;
}

template <class T>
void Chain<T>::StackPush(T data) {

    first = new ChainNode<T>(data, first);
    cout << "StackPush: " << data << endl;
}

template <class T>
void Chain<T>::StackPop(void) {

    ChainNode<T>* top = first;

    if(IsEmpty())
        cout << "StackPop: empty!" << endl;
    else {

        cout << "StackPop: " << top->data << endl;
        first = top->link;
        delete top;
    }
}

template <class T>
void Chain<T>::QueuePush(T data) {

    if(IsEmpty())
        first = last = new ChainNode<T>(data, NULL);
    else   
        last = last->link = new ChainNode<T>(data, NULL);

    cout << "QueuePush: " << data << endl;
}

template <class T>
void Chain<T>::QueuePop(void) {

    ChainNode<T>* front = first;

    if(IsEmpty()) 
        cout << "QueuePop: empty!" << endl;
    else {
        cout << "QueuePop: " << front->data << endl;
        first = front->link;
        delete front;
    }
}

int main(void) {

    Chain<int> chain;

    cout << "---Test: Linked Stack" << endl;
    chain.StackPush(1);
    chain.StackPush(2);
    chain.StackPush(3);

    chain.Print();

    chain.StackPop();
    chain.StackPop();
    chain.StackPop();
    chain.StackPop();

    cout << "\n---Test: Linked Queue" << endl;
    chain.QueuePush(1);
    chain.QueuePush(2);
    chain.QueuePush(3);

    chain.Print();
    
    chain.QueuePop();
    chain.QueuePop();
    chain.QueuePop();
    chain.QueuePop();
}