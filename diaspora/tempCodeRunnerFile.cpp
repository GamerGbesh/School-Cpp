
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
            case EXIT:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (userChoice != EXIT);
    
    return 0;
}


void doubleNumber(randomInt &number) {
    number *= 2; 
    lessthan10(number);

}

void reverseDigits(randomInt &number) {
    string reverseNumber = to_string(number);
    char temp = reverseNumber[0];
    int size = reverseNumber.size();
    for (int i = 0; i < size; i ++){
        reverseNumber[i] = reverseNumber[size - i - 1];
    }
    reverseNumber[size - 1] = temp;
    number = stoi(reverseNumber);
    cout << "The reversed number is: " << reverseNumber << endl;
    lessthan10(number);
    
}

void raiseNumber(randomInt &number){
    int randomPower = rand()% (4 - 2 + 1) + 2;
    cout << "The number would be raised to the power of " << randomPower << endl;