/*
Name: Mensah Philemon Edem Yao
Id: 22042860
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <algorithm>


typedef int randomInt;

enum selection{
    EXIT = 0,
    DOUBLE,
    REVERSE,
    RAISE,
    SUMDIGITS,
    RAISETWO,
    RAISETHREE,
    GENERATERANDOM,
};


//Function prototypes
void doubleNumber(randomInt &number);
void reverseDigits(randomInt &number);
void raiseNumber(randomInt &number);
void sumOfDigits(randomInt &number);
void raisetwo(randomInt &number);
void raisethree(randomInt &number);
void lessthan10(randomInt &number);
void isPrime(randomInt &number);
randomInt generateRandom();


using namespace std;
int main() {
    srand(time(nullptr));
    randomInt randomNumber = generateRandom();
    int userChoice;
    do
    {
        // Menu
        cout << "\033[0m";
        cout << "\nMenu:\n";
        cout << "0. Exit\n";
        cout << "1. Double the number\n";
        cout << "2. Reverse the digits\n";
        cout << "3. Raise the number to the power of 2, 3 or 4\n";
        cout << "4. Sum of the digits\n";
        cout << "5. Raise first digit of two-digit number to the power of second number\n";
        cout << "6. Raise first two digits of three-digit number to the power of third number\n";
        cout << "7. Generate a new random number\n";
        cout << "Enter your choice: ";
        cin >> userChoice;
        cout << "\n\033[0m------------------------------------------------------\n";
        cout << "\033[32m";

        switch (userChoice) {
            case DOUBLE:
                doubleNumber(randomNumber);
                break;
            case REVERSE:
                reverseDigits(randomNumber);
                break;
            case RAISE:
                raiseNumber(randomNumber);
                break;
            case SUMDIGITS:
                sumOfDigits(randomNumber);
                break;
            case RAISETWO:
                raisetwo(randomNumber);
                break;
            case RAISETHREE:
                raisethree(randomNumber);
                break;
            case GENERATERANDOM:
                randomNumber = generateRandom();
                break;
            case EXIT:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "\033[31mInvalid choice. Please try again.\n";
        }
        cout << "\033[0m------------------------------------------------------\n";
    } while (userChoice != EXIT);
    
    return 0;
}

// This function doubles the number
void doubleNumber(randomInt &number) {
    number *= 2; 
    lessthan10(number);

}

// This function reverses the digits of the number
void reverseDigits(randomInt &number) {
    string reverseNumber = to_string(number);
    reverse(reverseNumber.begin(), reverseNumber.end());
    number = stoi(reverseNumber);
    cout << "The reversed number is: " << reverseNumber << endl;
    lessthan10(number);
    
}

// This function raises the number to a random power of 2, 3, or 4
void raiseNumber(randomInt &number){
    int randomPower;
    cout << "Raise the number to the power of(2, 3 or 4): ";
    cin >> randomPower;
    while (randomPower != 2 && randomPower != 3 && randomPower != 4) {
        cout << "\033[31mInvalid choice. Please try again.\n";
        cout << "\033[32mRaise the number to the power of(2, 3 or 4): ";
        cin >> randomPower;
    }
    cout << "The number is raised to the power of " << randomPower << endl;
    number = pow(number, randomPower);
    lessthan10(number);
}

// This function sums the digits of the number
void sumOfDigits(randomInt &number) {
    int sum = 0;
    string summedDigits = to_string(number);
    for (int i = 0; i < summedDigits.size(); i++){
        sum += summedDigits[i] - '0';
    }
    number = sum;
    lessthan10(number);
}

// This function raises the first digit to the power of the second digit
void raisetwo(randomInt &number){
    string digits = to_string(number);
    int size = digits.size();
    if (size == 2){
        int firstNum = digits[0] - '0';
        int secondNum = digits[1] - '0';
        number = pow(firstNum, secondNum);
    }
    else {
        cout << "\033[31mNumber is not a two-digit number"<< endl;
    }
    lessthan10(number);
}

// This function raises the first and second digits to the power of the third digit only if the third digit is less than or equal to 4
void raisethree(randomInt &number){
    string digits = to_string(number);
    int size = digits.size();
    if (size == 3){
        int firstNum = digits[0] - '0';
        int secondNum = digits[1] - '0';
        int thirdNum = digits[2] - '0';
        if (thirdNum <= 4){
            int combined = firstNum * 10 + secondNum;
            number = pow(combined, thirdNum);
        }
        else {
            cout << "\033[31mThe last number is greater than 4\n";
        }
    }
    else{
        cout << "\033[31mThe number is not a three-digit number\n";
    }
    lessthan10(number);
}

// This function increases the result by 10 if the result of the previous used function is less than 10
void lessthan10(randomInt &number){
    if (number < 0){
        cout << "\033[31mThe result of the operation is greater than the range of int\nA new random number would be generated.\n";
        number = generateRandom();
        return;
    }
    else if (number < 10){
        cout << "The resulting number is " << number << endl;
        cout << "The number is less than 10 so 10 would be added to it\n";
        number += 10;
    }
    cout << "The resulting number is " << number << endl;
    isPrime(number);
}

// This function checks if the number is prime
void isPrime(randomInt &number){
    if (number < 2){
        cout << "The number is not prime!" << endl;
    }
    else if (number % 2 == 0 || number % 3 == 0 || number % 5 == 0 || number % 7 == 0){
        cout << "The number is not prime!" << endl;
    }
    else{
        cout << "The number is prime!" << endl;
    }
}

// This function is used to generate a random number
randomInt generateRandom(){
    randomInt randomNumber = rand() % (99 - 10 + 1) + 10;
    cout << "\033[32mThe random number generated is: "<< randomNumber << endl;
    return randomNumber;
}