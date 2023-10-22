#include <iostream>
using namespace std;

class Element {
public:
    int key;
};

class Loser {
private:
    int *loser;
    int k; // loser tree의 size
public:
    Loser(Element*, int);
    void constructTree(Element* R);
};

Loser::Loser(Element* R, int sz = TreeSize) {

    k = sz;
    loser = new int[k]; // loser[0]은 최종 winner를 포함함
    for(int i = 1; i < k; i++) 
        loser[i] = -1;
}

void Loser::constructTree(Element* R) {

    int i;
    int j = k;
    for(i = k-1; (i >= k/2) && (j != 1); i--) {

        // 각 트리의 leafNode에서 토너먼트
        if(R[j].key > R[j-1].key)
            winner[i] = j-1; // 아마 R[j-1].key인듯
        else
            winner[i] = j;
        j -= 2;
    }
    if(j == 1) {

        // 트리 내에 child를 하나만 가진 노드가 존재할 경우
        // 이 노드로 토너먼트 진행
        winner[k/2] = 1;
        int challenger = winner[(k/2)*2];
        if(R[challenger].key < R[1].key)
            winner[k/2] = challenger;
    }
    for(i = (k/2)-1; i>= 1; i--) {
        
        // internal node에서 토너먼트 진행
        // bottom부터 root까지 위로 moving
        j = 2*i;
        if(R[winner[j]].key > R[winner[j+1]].key)
            winner[i] = winner[j+1];
        else
            winner[i] = winner[j];
    }
}