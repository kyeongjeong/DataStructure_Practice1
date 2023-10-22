#include <iostream>
#include <algorithm>
#pragma warnig(disable:4996)
using namespace std;

template <class T>
class MaxHeap {
private:
    T* heap;
    int heapSize;
    int capacity;

public:
    MaxHeap(int theCapacity = 10);
    void Push(const T& e);
    void Pop();
    bool IsEmpty() { return (heap == NULL); }
};

template <class T>
MaxHeap<T>::MaxHeap(int theCapacity = 10) {
    
    if(theCapacity < 1)
        throw "Capacity must be >= 1";
    capacity = theCapacity;
    heapSize = 0;
    heap = new T[capacity + 1];
}

template <class T>
void MaxHeap<T>::Push(const T& e) {

    // e를 max heap에 삽입
    if(heapSize == capacity) { // capacity를 2배로 늘리기

        ChangeSize1D(heap, capacity, 2*capacity);
        capacity *= 2;
    }

    int currentNode = ++heapSize;
    while((currentNode != 1) && (heap[currentNode/2] < e)) { // bubble up

        heap[currentNode] = heap[currentNode/2]; // parent에 있던 값을 현재 노드로 복사
        currentNode /= 2; // 현재 노드의 위치를 parent로 이동
    }
    heap[currentNode] = e;
}

template <class T>
void MaxHeap<T>::Pop() { // Max element 삭제

    if(IsEmpty()) 
        throw "Heap is empty. Cannot delete.";
    heap[1].~T(); // Max element 삭제

    // 배열의 마지막 element를 heap에서 삭제
    T lastE = heap[heapSize--];

    // trickle down
    int currentNode = 1; // root
    int child = 2; // currentNode의 child
    while(child <= heapSize) {

        // currentNode의 자식 노드중 더 큰 노드를 child로 설정
        if((child < heapSize) && (heap[child] < heap[child+1])) 
            child++;
        if(lastE >= heap[child]) // lastE의 값을 currentNode에 넣어도 되는가?
            break;
        
        heap[currentNode] = heap[child]; // child를 up
        currentNode = child; // level을 낮추기
        child *= 2;
    }
    heap[currentNode] = lastE;
}

template <class T>
void ChangeSize1D(T*& a, const int oldSize, const int newSize) {

    if(newSize < 0)
        throw "New length must be >= 0";
    
    T* temp = new T[newSize]; // 새로운 배열 생성
    int number = min(oldSize, newSize); // number to copy
    copy(a, a+number, temp);
    delete[] a; // old memory 해제
    a = temp;
}