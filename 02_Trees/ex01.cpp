#include <iostream>
using namespace std;

template <class T>
class TreeNode {

    T data;
    TreeNode<T> *leftChild, *rightChild;

    TreeNode() { leftChild = rightChild = NULL; }
};

template <class T>
void PreOrder(TreeNode<T>* t) {

    if(t != NULL) {
        
        cout << t << endl;
        PreOrder(t->leftChild);
        PreOrder(t->rightChild);
    }
}

template <class T>
void InOrder(TreeNode<T>* t) {

    if(t != NULL) {

        InOrder(t->leftChild);
        cout << t << endl;
        InOrder(t->rightChild);
    }
}

template <class T>
void PostOrder(TreeNode<T>* t) {

    if(t != NULL) {

        PostOrder(t->leftChild);
        PostOrder(t->rightChild);
        cout << t << endl;
    }
}

// 이 부분은 오류 나는 게 맞음
template <class T>
void LevelOrder() {

    Queue<TreeNode<T>*> q;
    TreeNode<T>* currentNode = root;

    while(currentNode) {

        Visit(currentNode);

        if(currentNode->leftChild)
            q.push(currentNode->leftChild);
        if(currentNode->rightChild)
            q.push(currentNode->rightChild);

        if(q.IsEmpty())
            return;
        
        currentNode = q.Front();
        q.Pop();
    }
}

int main() {

    return 0;
}