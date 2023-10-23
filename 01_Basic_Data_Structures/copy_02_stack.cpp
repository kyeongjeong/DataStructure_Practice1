#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class Stack {
public:
    Stack(int stackCapacity  = 10);
    ~Stack() { delete[] stack; }
    bool IsEmpty() const;
    T &Top() const;
    void Push(const T &item);
    void Pop();

private:
    T *stack;
    int top;
    int capacity;
};

template <class T>
Stack<T>::Stack(int stackCapacity):capacity(stackCapacity) {

   
}

template <class T>
inline bool Stack<T>::IsEmpty() const { return top == -1 }

template <class T>
inline T &Stack<T>::Top() const {

}

template <class T>
void Stack<T>::Push(const T &x) {

}

template <class T>
void ChangeSize1D(T *&a, const int oldSize, const int newSize) {

}

template <class T>
void Stack<T>::Pop() {

}

int main() {

    return 0;
}