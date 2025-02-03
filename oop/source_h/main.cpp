#include "atm.h"

int main() {
    ATM atm("First");
    ATM atm2("Second");

    atm.deposit(1000);
    atm.withdraw(500);
    atm.transfer(&atm2, 200);

    std::cout << atm.show_balance() << std::endl;
    std::cout << atm2.show_balance() << std::endl;

    return 0;
}