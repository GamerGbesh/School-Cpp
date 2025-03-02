#include "3.cpp"
using namespace std;

class cylinderType: public circleType{
    private:
        double height;

    public:
        void volume(){
            cout << "Volume: " << area() * height << endl;
        }
        void surface(){
            cout << "Area: " << (circumference() * height) + (2 * area()) << endl;
        }
        void setHeight(double h){
            height = h;
        }
        void setCylinderRadius(double r){
            setRadius(r);
        }
};

int main(){
    cylinderType cylinder;
    cylinder.setCylinderRadius(5);
    cylinder.setHeight(4);

    cylinder.volume();
    cylinder.surface();
}