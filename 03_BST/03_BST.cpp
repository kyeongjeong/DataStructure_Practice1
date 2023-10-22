#include <iostream>
using namespace std;

template <class K, class E>
class TreeNode {
public:
    TreeNode(const pair<K, E>& thePair);
    pair<K, E> data;
    TreeNode* leftChild;
    TreeNode* rightChild;
};

template <class K, class E>
class BST {
private:
    TreeNode<pair<K, E>>* root;
public:
    BST();
    pair<K, E>* Get(const K& k);
    pair<K, E>* Get(TreeNode<pair<K, E>>* p, const K& k);
    void Insert(const pair<K, E>& thePair);
    void Delete(K k);
};

template <class K, class E>
pair<K, E>* BST<K, E>::Get(const K& k) {

    // k라는 key를 가진 (*this)를 BST에서 찾기
    // pair를 찾으면, pair의 pointer를 반환. 이외의 경우에는 NULL을 반환
    return Get(root, k);
}

template <class K, class E>
pair<K, E>* BST<K, E>::Get(TreeNode<pair<K, E>>* p, const K& k) {

    if (p == nullptr)
        return nullptr;
    if (k < p->data.first)
        return Get(p->leftChild, k);
    if (k > p->data.first)
        return Get(p->rightChild, k);
    
    return &p->data;
}

template <class K, class E> 
void BST<K,E>::Insert(const pair<K,E>& thePair) {

    // thePair를 BST에 삽입
    // thePair.first를 검색
    // pp는 p의 parent

    TreeNode<pair<K,E>>* p = root, *pp = NULL;
    while(p) {

        pp = p;
        if(thePair.first < p->data.first)
            p = p->leftChild;
        else if(thePair.first > p->data.first)
            p = p->rightChild;
        else { // 중복된 값인 경우, 해당 key의 element를 update 
            
            p->data.second = thePair.second;
            return;
        }
    }

    // 삽입 수행
    p = new TreeNode<pair<K,E>> (thePair);
    if(root != NULL) { // 트리가 비어 있지 않은 경우

        if(thePair.first < pp->data.first)
            pp->leftChild = p;
        else
            pp->rightChild = p;
    }
    else
        root = p;
}

template <class K, class E> 
void BST<K,E>::Delete(K k) {

    // q는 p의 parent

    TreeNode<pair<K,E>>*p = root, *q = 0;
    while(p && (k != p->data.first)) {

        q = p;
        if(k < p->data.first)
            p = p->leftChild;
        else   
            p = p->rightChild;
    }

    if(p == 0) // 찾지 못한 경우
        return;
    
    if((p->leftChild == 0) && (p->rightChild == 0)) { // p가 leaf인 경우
        
        if(q == 0)
            root = 0;
        else if(q->leftChild == p)
            q->leftChild == 0;
        else
            q->rightChild = 0;
        
        delete p;
        return;
    }

    if(p->leftChild == 0) { // p가 rightChild만 가지고 있을 경우
        
        if(q == 0)
            root = p->rightChild;
        else if(q->leftChild == p)
            q->leftChild == p->rightChild;
        else
            q->rightChild = p->rightChild;
        
        delete p;
        return;
    }

    if(p->rightChild == 0) { // p가 leftChild만 가지고 있을 경우
        
        if(q == 0)
            root = p->leftChild;
        else if(q->leftChild == p)
            q->leftChild == p->leftChild;
        else
            q->rightChild = p->leftChild;
        
        delete p;
        return;
    }

    TreeNode<pair<K,E>> *prevprev = p, *prev = p->rightChild, *curr = p->righChild->leftChild;
    while(curr) {

        prevprev = prev;
        prev = curr;
        curr = curr->leftChild;
    }
    // curr은 0이고, prev는 삭제되어야 할 노드이며, prevprev는 prev의 parent이다.
    // prev의 leftChild는 0이어야 한다.
    p->data = prev->data;
    if(prevprev == p)
        prevprev->rightChild = prev->rightChild;
    else
        prevprev->leftChild = prev->rightChild;
        
    delete prev;
    return;
}