#include <iostream>
using namespace std;
class bagType
{
public:
    void set(string, double, double, double, double);
    void print() const;
    string getStyle() const;
    double getPrice() const;
    void get(double, double, double, double);
    bagType();
    bagType(string, double, double, double, double);
private:
    string style;
    double l;
    double w;
    double h;
    double price;
};

bagType::bagType(string style, double length, double width, double height, double price): 
style(style), l(length), w(width), h(height), price(price){}


// a
void bagType::set(string style, double length, double width, double height, double price){
    this->style = style;
    this->l = length;
    this->w = width;
    this->h = height;
    this->price = price;
}

//b
void bagType::print() const{
    cout << string(50, '-') << endl;
    cout << "Style: " << style << endl;
    cout << "Length: " << l << endl;
    cout << "Width: " << w << endl;
    cout << "Height: " << h << endl;
    cout << "Price: " << price << endl;
    cout << string(50, '-') << endl;
}

//c
bagType::bagType(){
    style = "";
    l = 0.0;
    w = 0.0;
    h = 0.0;
    price = 0.0;
}

string bagType::getStyle() const{
    return style;
}

double bagType::getPrice() const{
    return price;
}


int main (){
    bagType newBag;
    newBag.set("Tote", 12, 12, 12, 12);
    //d
    newBag.print();

    //e
    bagType tempBag("backPack", 15, 8, 20, 49.99);
    tempBag.print();
}