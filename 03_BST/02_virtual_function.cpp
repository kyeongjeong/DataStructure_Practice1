#include <iostream>
using namespace std;

class BaseClass {
public:
    virtual void print(void) const { cout << "Base class\n"; }
};

class DervClass: public BaseClass {
public:
    virtual void print(void) const { cout << "Derived class\n"; }
};

int main() {

    BaseClass *objPtr = new BaseClass;
    objPtr->print();
    delete objPtr;

    objPtr = new DervClass;
    objPtr->print();
    delete objPtr;
}