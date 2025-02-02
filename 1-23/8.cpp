#include <iostream>
using namespace std;
class employee  
{  
public:  
    employee();  
    employee(string, int, double);  
    employee(int, double);  
    employee(string);  
    void setData(string, int, double);  
    void print() const;  
    void updatePay(double x);  
    int getNumOfServiceYears() const;  
    double getPay() const;  
private:  
    string name;  
    int numOfServiceYears;  
    double pay;  
};


employee::employee(){
    name = "";
    numOfServiceYears = 0;
    pay = 0.0;
}


employee::employee(string n, int y, double p){
    name = n;
    numOfServiceYears = y;
    pay = p;
}


employee::employee(int y, double p){
    name = "";
    numOfServiceYears = y;
    pay = p;
}

employee::employee(string n){
    name = n;
    numOfServiceYears = 0;
    pay = 0.0;
}

// a
void employee::setData(string n, int y, double p){
    name = n;
    numOfServiceYears = y;
    pay = p;
}

// b 
void employee::print() const{
    cout << string(50, '-') << endl;
    cout << "Name: " << name << endl;
    cout << "Number of Service Years: " << numOfServiceYears << endl;
    cout << "Pay: " << pay << endl;
    cout << string(50, '-') << endl;
}

// c
void employee::updatePay(double x){
    this->pay = x;
}

// d
int employee::getNumOfServiceYears() const{
    return numOfServiceYears;
}

// e
double employee::getPay() const{
    return pay;
}

int main(){
    // f
    employee emp1;
    emp1.setData("John", 2, 2000);
    emp1.print();

    employee emp2("Jane");
    emp2.print();
}