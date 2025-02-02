#include <iostream>
#include <iomanip>
using namespace std;


double PI = 3.14;

class temporary
{
public:
    void set(string, double, double);
    void print();
    double manipulate();
    void get(string&, double&, double&);
    void setDescription(string);
    void setFirst(double);
    void setSecond(double);
    string getDescription() const;
    double getFirst()const;
    double getSecond()const;
    temporary(string = "", double = 0.0, double = 0.0);
private:
    string description;
    double first;
    double second;
};

// a
void temporary::set(string desc, double f, double s){
    description = desc;
    first = f;
    second = s;
}

// b
double temporary::manipulate(){
    if (this->description == "rectangle"){
        return this->first * this->second;
    }
    else if (this->description == "circle"){
        return PI * this->first * this->first;
    }
    else if (this->description == "sphere"){
        return 4/3 * PI * this->first * this->first * this->first;
    }
    else if (this->description == "cylinder"){
        return PI * this->first * this->first * this->second;
    }
    else{
        return -1;
    }
}

// c
void temporary::print(){
    if (this->description == "rectangle"){
        cout << "rectangle: " << "length = " << this->first << ", width = "<< this->second << ", area = "<<this->manipulate() << endl;
    }
    else if (this->description == "circle"){
        cout << "circle: " << "radius = " << this->first << ", area = "<<this->manipulate() << endl;
    }
    else if (this->description == "sphere"){
        cout << "sphere: " << "radius = " << this->first << ", volume = "<<this->manipulate() << endl;
    }
    else if (this->description == "cylinder"){
        cout << "cylinder: " << "radius = " << this->first << ", height = "<< this->second << ", volume = "<<this->manipulate() << endl;
        }
    else{
        cout << "Invalid description" << endl;
    }
}

// d
temporary::temporary(string desc, double f, double s){
    set(desc, f, s);
}

// e
void temporary::get(string& desc, double& f, double& s){
    cout << string(50, '-') << endl;
    cout << "Description: " << this->description << endl;
    cout << "First: " << this->first << endl;
    cout << "Second: " << this->second << endl;
    cout << string(50, '-') << endl;
}

void temporary::setFirst(double f){
    this->first = f;
}

void temporary::setSecond(double s){
    this->first = s;
}

void temporary::setDescription(string desc){
    this->description = desc;
}

string temporary::getDescription() const{
    return this->description;
}

double temporary::getFirst() const{
    return this->first;
}

double temporary::getSecond() const {
    return this->second;
}


int main(){
    temporary object1;
    temporary object2("rectangle", 8.5, 5);
    temporary object3("circle", 6, 0);
    temporary object4("cylinder", 6, 3.5);
    cout << fixed << showpoint << setprecision(2);
    object1.print();
    object2.print();
    object3.print();
    object4.print();
    object1.set("sphere", 4.5, 0);
    object1.print();
}

