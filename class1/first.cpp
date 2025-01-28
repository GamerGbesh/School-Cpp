#include <iostream>

using namespace std;

class ClockType{
    private:
        int hr;
        int min;
        int sec;

    public:

        ClockType(int hr, int min, int sec){
            setTime(hr, min, sec);
        }

        void setTime(int hr, int min, int sec) {
            this->hr = hr;
            this->min = min;
            this->sec = sec;
        }
        void getTime(int & hr, int & min, int & sec){
            this->printTime();
        }
        void printTime(){
            cout << this->hr << ":" << this->min << ":" << this->sec << endl;
        }
        int incrementSeconds(){

        }
        int incrementMinutes(){

        }
        int incrementHours(){

        }
        bool equalTime(const ClockType & clock){

        }

        
};


int main(){
    ClockType clock(12, 30, 54);
    clock.setTime(14, 30, 54);
    clock.printTime();
}
