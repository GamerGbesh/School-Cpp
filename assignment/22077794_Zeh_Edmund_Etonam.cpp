/*NAME: Zeh Edmund Etonam
  ID: 22077794*/


#include <iostream>
#include <ctime>
#include <math.h>
#include <algorithm>
using namespace std;

typedef int rand_int;

enum menu {
        DOUBLE = 1,
        REVERSE = 2,
        RAISE = 3,
        SUM =4,
        RaiseToSecond = 5,
        RAISETOTHREE = 6,
        RANDNUM = 7,
        EXIT = 0
};

void doubleNum(rand_int &num, string line);
void reverseNum(rand_int &num, string line);
void raiseNum(rand_int &num, string line);
void sumOfNum(rand_int &num, string line);
void firstNumPowSecondNum( rand_int &num, string line);
void genRanNum(rand_int &num, string line);
void checkLessThan10(rand_int &num);
void checkNumPrime(rand_int &num);
int checkNumEQUALthree(rand_int &num);
int checkLastNumIsLessOrEQUALFour(rand_int &num);
void raiseToThirdNum(rand_int &num, string line);

void lines(string line);

int main(){

    srand(time(NULL));

    rand_int randInt= rand() % 90 + 10;
    cout <<"Random number: " <<randInt;
    int choice;

    string line = "_____________________________________________";

    do{
        cout <<"\n********************MENU********************\n";
        cout <<"Enter numbers(0-7) only to perform following operation\n";
        cout <<"0. EXIT\n";
        cout <<"1. Double the number.\n";
        cout <<"2. Reverse the number.\n";
        cout <<"3. Raise the number randomly to either 2,3 or 4\n";
        cout <<"4. Sum the digits of the number.\n";
        cout <<"5. Raise the first digit of the number to second digit if the number is a two digit number.\n";
        cout <<"6. Raise the first two digits of the number to the third if the number is a three digit number.\n";
        cout <<"7. Generate new random number.\n"; 
        cout <<"Enter number choice: ";

        cin >> choice;

        switch(choice){
            case DOUBLE:
                doubleNum(randInt,line);
                break;
            case REVERSE:
                reverseNum(randInt, line);
                break;
            case RAISE:
                raiseNum(randInt, line);
                break;
            case SUM:
                sumOfNum(randInt, line);
                break;
            case RaiseToSecond:
                firstNumPowSecondNum(randInt, line);
                break;
            case RAISETOTHREE:
                raiseToThirdNum(randInt, line);
                break;
            case RANDNUM:
                genRanNum(randInt, line);
                break;
            case EXIT:
                cout <<"Exiting program!.\n";
                break;
            default:
                cout <<"Entered number must be (1 - 6) only\n";
        }

    cout <<"\n*********************END*********************\n";
    } while(choice !=0);
    return 0;
}

void doubleNum(rand_int &num, string line){
    lines(line);
    cout <<"\nDouble of " <<num <<": ";
    num *= 2;
    if(num < 10)
    num += 10;
    cout <<num <<'\n';
    checkLessThan10(num);
    checkNumPrime(num);
    lines(line);
}

void reverseNum(rand_int &num, string line){
    lines(line);
    cout <<"\nThe reverse of " <<num <<": ";
    string s1 = to_string(num);
    reverse(s1.begin(), s1.end());
    num = stoi(s1);
    cout <<num <<'\n';
    checkLessThan10(num);
    checkNumPrime(num);
    lines(line);
}

void raiseNum(rand_int &num, string line){
    lines(line);
    int num2;
    cout <<"Enter number(2-4) to raise " <<num <<" to power number entered: ";
    cin >> num2;
    cout <<"\n" << num; 
    num = pow(num, num2);
    if(num < 0){
        cout <<" Result is outside the range of int.! Generate new random number(7)\n";
        lines(line);
    }
    else{
        cout <<" raised to the power " <<num2<<": " <<num <<'\n';
        checkLessThan10(num);
        checkNumPrime(num);
        lines(line);
    }
}

void sumOfNum(rand_int &num, string line){
    lines(line);
    cout <<"Sum of digits of " <<num <<": ";
    string s1 = to_string(num);
    int temp = 0;
    for(int i = 0; i < s1.size(); i++){
        temp += int(s1[i]-'0');
    }
    num = temp;
    cout <<num <<'\n';
    checkLessThan10(num);
    checkNumPrime(num);
    lines(line);
}

void firstNumPowSecondNum( rand_int &num, string line){
    lines(line);
    string s1 = to_string(num);
    cout <<"Raising the first digit of " <<s1 <<"(" <<s1[0] <<") to " 
    <<"the second digit of " <<s1 <<"(" <<s1[1] <<"): "; 
    int temp1;
    int temp2;
    if(s1.size() == 2){
        temp1 = int(s1[0]-'0');
        temp2 = int(s1[1]-'0');
        num = pow(temp1,temp2);
        cout <<num <<'\n';
    }
    checkLessThan10(num);
    checkNumPrime(num);
    lines(line);
}

void genRanNum(rand_int &num, string line){
    lines(line);
    num = rand() % 90 + 10;
    cout <<"New random num: "<<num <<"\n";
    lines(line);
}

void checkLessThan10(rand_int &num){
    if(num < 10){
        cout << num;
        num += 10;
        cout <<" is less than 10. Adding 10 to num: " << num <<"\n";
    }
}

void checkNumPrime(rand_int &num){
    if(num < 2){
        cout <<num <<" is not a prime number!\n";
    }
    
    else if(num % 2 == 0 || num % 3 == 0 || num % 5 == 0 || num % 7 == 0){
        cout <<num <<" is not a prime number!\n";
    }

    else
        cout <<num <<" is a prime number!\n";
}

int checkNumEQUALthree(rand_int &num){
    string s1 = to_string(num);
    if(s1.size() == 3){
        num = stoi(s1);
        return s1.size();
    }
    else{
        num = stoi(s1);
        return 0;}
}

int checkLastNumIsLessOrEQUALFour(rand_int &num){
    string s1 = to_string(num);
    int temp = (s1[s1.size()-1]) - '0';
    if(temp <= 4){
        return temp;
    }
    else 
        return 100;
}

void raiseToThirdNum(rand_int &num, string line){
    if(checkNumEQUALthree(num) == 3 && checkLastNumIsLessOrEQUALFour(num) <= 4){

        string s1 = to_string(num);

        lines(line);

        cout <<"\n Raising the first two digits of " <<s1 <<"(" <<s1[0] <<s1[1] <<")" <<" raised to the power of the last digit of " 
        <<s1 <<"(" <<s1[2] <<")" <<": ";
        string s2;
        for(int i = 0; i < s1.size()-1; i++){
            s2 += s1[i];
        }
        int temp1 = stoi(s2);
        int temp2 = (s1[s1.size()-1]) - '0';
        num = pow(temp1,temp2);
        cout << num <<'\n';

        lines(line);
    }
    else{
        cout << num <<" is either not a three digit number or the last number is greater than 4!\n";
        lines(line);
    }
}

void lines(string line){
    cout <<line <<'\n';
}