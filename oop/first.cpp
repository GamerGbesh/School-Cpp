#include <iostream>

using namespace std;


class Car{
    private:
        string company;
        int seatNumber;
        string color;
        int wheels;
        int speed;

    public:
        Car(string company, int seatNumber, string color, int wheels, int speed): company(company), seatNumber(seatNumber), 
        color(color), wheels(wheels), speed(speed){
            // company_setter(company);
            // seat_setter(seatNumber);
            // color_setter(color);
            // wheels_setter(wheels);
            // speed_setter(speed);
        }

        void company_setter(string company){
            this->company = company;
        }

        string company_getter(){
            return this->company;
        }

        void seat_setter(int seatNumber){
            this->seatNumber = seatNumber;
        }
        int seat_getter(){
            return this->seatNumber;
        }

        void color_setter(string color){
            this->color = color;
        }
        string color_getter(){
            return this->color;
        }

        void wheels_setter(int wheels){
            this->wheels = wheels;
        }
        int wheels_getter(){
            return this->wheels;
        }

        void speed_setter(int speed){
            this->speed = speed;
        }
        int speed_getter(){
            return this->speed;
        }
};


int main(){
    Car car("BMW", 2, "Blue", 4, 35);
    cout << car.company_getter() << endl;
    cout << car.seat_getter() << endl;
    cout << car.color_getter() << endl;
    cout << car.wheels_getter() << endl;
    cout << car.speed_getter() << endl;
}