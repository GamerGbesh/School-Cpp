#include <iostream>
using namespace std;

class Animal {
public:
    // Virtual function to allow overriding in derived classes
    virtual void sound() {
        cout << "Some generic animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    // Override the virtual function
    void sound() override {
        cout << "Woof!" << endl;
    }
};

int main() {
    Animal* pet = new Dog();  // Base class pointer points to a derived class object
    pet->sound();             // Calls Dog's sound() due to virtual dispatch
    delete pet;
    return 0;
}
