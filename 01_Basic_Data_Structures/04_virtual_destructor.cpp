#include <iostream>
using namespace std;

class Base {
public:
    ~Base() {
        cout << "Base destructor!" << endl;
    }
};

class Derived : public Base {
public:
    char* largeBuffer;

    Derived() {
        largeBuffer = new char[3000];
    }

    ~Derived() {
        cout << "Derived destructor!" << endl;
        delete[] largeBuffer;
    }
};

int main() {

    //코드1
    cout << "--Derived* der1 = new Derived()---" << endl;
    Derived* der1 = new Derived();
    delete der1;

    //코드2
    cout << "\n\n--Derived* der1 = new Derived()---" << endl;
    Base* der2 = new Derived();
    delete der2;
}