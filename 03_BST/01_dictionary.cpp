#include <iostream>
using namespace std;

template<class K, class E>
class Dictionary {
public:
    virtual void Ascend(void) const = 0;
    // dictionary를 key에 따라 오름차순으로 정렬하여 출력

    virtual pair<K,E>*Get(const K&) const = 0;
    // 특정 key 값을 가진 pair의 pointer를 return. 만약 해당 pair가 없다면 NULL을 반환.

    virtual void Insert(const pair<K,E>&) = 0;
    // 주어진 pair를 삽입. 만약 key값이 중복된다면, 이미 존재하는 element의 값을 update

    virtual void Delete(const K&) = 0;
    // 특정 key 값을 가진 pair를 삭제.
};