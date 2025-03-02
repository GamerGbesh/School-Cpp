#include "bank.h"
#include <iostream>
#include <string>


int main(){
    BankAccount one("James", "checking", 0, 2);
    BankAccount two("Micheal", "saving", 0, 5);
    one.deposit(600);
    two.deposit(200);
    one.withdraw(200);
    one.transfer(200, two);
    two.checkBalance();

}