#include <iostream>
using namespace std;

class testClass
{
public:
    int sum();
    void print() const;
    testClass();
    testClass(int a, int b);
    
private:
    int x;
    int y;
};

// a
testClass::testClass(){
    x = 0;
    y = 0;
}

testClass::testClass(int a, int b){
    x = a;
    y = b;
}

int testClass::sum(){
    return x + y;
}

void testClass::print() const{
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

// b
int main(){
    testClass object1;
    testClass object2(5, 10);
    cout << "object1: " << object1.sum() << endl;
    cout << "object2: " << object2.sum() << endl;
    object1.print();
    object2.print();
}