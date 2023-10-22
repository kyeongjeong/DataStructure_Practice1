#include <iostream>
using namespace std;

class Test {
private:
    int n;

public:
    int constFunc(int t) const {

        /* n = 3; // n은 멤버변수기 때문에 불가능 */
        t = 6; // 멤버변수가 아닌 인자로 받은 값은 수정 가능

        /* nonConstFunc(3); // const가 아닌 멤버 함수 호출 불가능 */
        return t;
    }

    int nonConstFunc(int t) {

        n = 3;

        constFunc(3);
        return n;
    }
};

int main(void) {

    Test test1 = Test();
    cout << test1.nonConstFunc(3) << endl;

    Test test2 = Test();
    test2.constFunc(3); // 호출 불가능. 
    // const 객체를 다룰 때는 const가 아닌 멤버 함수를 호출할 수 없음.
    // const 객체가 non-const 멤버 함수를 호출할 수 있게 되면, 의도치 않게 객체 내의 값의 변경이 일어날 수 있음.

    return 0;
}