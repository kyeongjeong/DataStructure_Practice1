#include <iostream>
using namespace std;

template <class T>
class Test {
public:
    Test();
    ~Test();
    T Data(T);
};

template <class T>
Test<T>::Test() {
    cout << "Constructor, allocate..." << endl;
}

template <class T>
Test<T>::~Test() {
    cout << "Desstructor, deallocate..." << endl;
}

template <class T>
T Test<T>::Data(T v) {
    return v;
}

int main() {

    Test<int> Var1;
    Test<double> Var2;
    Test<char> Var3;

    cout << Var1.Data(100) << endl;
    cout << Var2.Data(1.234) << endl;
    cout << Var3.Data('K') << endl;

    return 0;
}