#include <iostream>
using namespace std;

template<class K, class E> class AVL;

template<class K, class E>
class AvlNode {
    friend class AVL<K,E>;
private:
    K key;
    E element;
    int bf;
    AvlNode<K,E> *leftChild, rightChild;
public:
    AvlNode(const K&k, const E&e) {
        key = k;
        element = e;
        bf = 0;
        leftChild = rightChild = NULL;
    }
};

template<class K, class E>
class AVL {
private:
    AvlNode<K,E> *root;
public:
    AVL() : root(NULL) {};
    void Insert(const K&k, const E&e);
};

template<class K, class E>
void AVL<K,E>::Insert(const K&k, const E&e) {

    // special case: empty tree
    if(root == NULL) {
        root = new AvlNode<K,E>(k, e);
        return;
    }

    // phase 1: e가 들어갈 point 찾기
    AvlNode<K,E>*a = root,  // bf가 +-1인 노드와 가장 가까운 노드 a
                *pa = NULL, // a의 parent
                *p = root,  // tree 내에서 움직일 노드 p
                *pp = NULL, //p의 parent
                *rootSub = NULL;

    while(p != NULL) {
        
    }
}