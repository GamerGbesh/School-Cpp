#include <iostream>

using namespace std;

int main(){
    int num;
    cout << "Enter a number from 1 to 12\n";
    cin >> num;
    if (num == 1){
        cout << "January";
    }
    else if (num == 2){
        cout << "February";
    }
    else if (num == 3){
        cout << "March";
    }
    else if (num == 4){
        cout << "April";
    }
    else{
        cout << "You didn't enter a valid number";
    }
}