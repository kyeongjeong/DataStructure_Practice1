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
        
        if(p->bf != 0) {
            a = p;
            pa = pp;
        }
        if(k < p->key) { // left branch 가져오기
            pp = p;
            p = p->leftChild;
        }
        else if(k > p->key) { // right branch 가져오기
            pp = p;
            p = p->rightChild;
        }
        else { // k가 이미 tree 안에 존재하는 경우, e를 업데이트한다.
            p->element = e;
            return;
        }
    }

    // phase 2: insert 하고 rebalance하기. 
    //k가 tree 안에 없고, pp의 child로써 insert됨
    AvlNode<K,E> *y = new AvlNode<K,E>(k, e);
    if(k < pp->key)
        pp->leftChild = y;
    else
        pp->rightChild = y;
    
    // a에서 pp까지의 경로상의 노드의 균형 요인을 조정
    // a의 정의에 따라, 현재 이 경로 상의 모든 노드의 balance factor는 0임 
    // 그들의 새로운 balance factor는 +-1
    // d = +1은 k가 a의 left subtree에 삽입되는 것을 의미
    // d = -1은 k가 a의 right subtree에 삽입되는 것을 의미
    int d;
    AvlNode<K,E>    *b, // a의 child
                    *c; // b의 child

    if(k > a->key) {

        b = p = a->rightChild;
        d = -1;
    }
    else {
        b = p = a->leftChild;
        d = 1;
    }

    while(p != y) {

        if(k > p->key) { // right의 height가 1 증가
            p->bf = -1;
            p = p->rightChild;
        }
        else { // left의 height가 1 증가
            p->bf = 1;
            p = p->leftChild;
        }
    }

    // tree가 현재 unbalanced한가?
    if((a->bf == 0) || (a->bf + d == 0)) { // tree가 계속 balanced 할 경우
        a->bf += d;
        return;
    }

    // tree가 unbalced할 경우, rotation type을 지정
    if(d == 1) { //left imbalance

        if(b->bf == 1) { // rotation type: LL

            a->leftChild = b->rightChild;
            b->rightChild = a;
            a->bf = 0;
            b->bf = 0;
            rootSub = b; // b가 새로운 subtree의 root가 됨
        }

        else { // rotation type: LR

            c = b->rightChild;
            b->rightChild = c->leftChild;
            a->leftChild = c->rightChild;
            c->leftChild = b;
            c->rightChild = a;
            switch (c->bf)
            {
            case 0:
                b->bf = 0;
                a->bf = 0;
                break;
            case 1:
                a->bf = -1;
                b->bf = 0;
            case -1:
                b->bf = 1;
                a->bf = 0;
            }
            c->bf = 0;
            rootSub = c; // c가 새로운 subtree의 root가 됨
        }
    }
    else { // right imbalance

        if(b->bf == -1) { // rotation type: RR
            
            a->rightChild = b->leftChild;
            b->leftChild = a;
            a->bf = 0;
            b->bf = 0;
            rootSub = b; // b가 새로운 subtree의 root가 됨
        }

        else { // rotation type: RL

            c = b->leftChild;
            b->leftChild = c->rightChild;
            a->rightChild = c->leftChild;
            c->rightChild = b;
            c->leftChild = a;
            switch (c->bf)
            {
            case 0:
                b->bf = 0;
                a->bf = 0;
                break;
            case 1:
                b->bf = -1;
                a->bf = 0;
            case -1:
                a->bf = 1;
                b->bf = 0;
            }   
            c->bf = 0;
            rootSub = c; // c가 새로운 subtree의 root가 됨         
        }
    }

    if(pa == NULL)
        root = rootSub;
    else if(a == pa->leftChild)
        pa->leftChild = rootSub;
    else
        pa->rightChild = rootSub;
    return;
}