#include <iostream>
using namespace std;

class Element {
public:
    int key;
};

class Loser {
private:
    int *loser;
    int winner, l;
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
    
    // leaf에서 시작하여 가능한 한 상위 노드로 올라가며 일련의 토너먼트를 진행
    for(i = k-1; (i >= k/2) && (j != 1); i--) {

        // 각 트리의 leafNode에서 토너먼트
        if(R[j].key > R[j-1].key) {
            loser[i] = j;
            winner = j-1; // 아마 R[j-1].key인듯
        }
        else {
            loser[i] = j-1;
            winner = j;
        }
        j -= 2;

        l = i/2;
        while(loser[i] != -1) {

            if(R[loser[l]].key < R[winner].key) {

                int temp = winner;
                winner = loser[l];
                loser[l] = temp;
            }
            l/2;
        }
        loser[l] = winner;
    }
    if(j == 1) {

        // 트리 내에 child를 하나만 가진 노드가 존재할 경우에 대해 반복
        winner = 1;
        l = k/2;

        while(loser[l] != -1) {

            if(R[loser[l]].key < R[winner].key) {

                int temp = winner;
                winner = loser[l];
                loser[l] = temp;
            }
            l/2;
        }
        loser[l] = winner;
    }
}