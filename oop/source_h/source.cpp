#include "atm.h"

ATM::ATM(std::string name) : name(name), amount(0) {}

float ATM::show_balance() const {
    return amount;
}

void ATM::deposit(float amount) {
    if (amount < 0) {
        throw std::invalid_argument("Amount must be positive");
    }
    this->amount += amount;
    std::cout << "Deposit successful" << std::endl;
}

std::string ATM::get_name() const {
    return name;
}

void ATM::set_name(std::string new_name) {
    name = new_name;
}

void ATM::set_amount(float amount) {
    if (amount < 0) {
        throw std::invalid_argument("Amount must be positive");
    }
    char choice;
    std::cout << "Are you sure you want to set the amount to " << amount << "? (y/n)";
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        this->amount = amount;
    }
    else std::cout << "Cancelling Operation!\n";
}

void ATM::withdraw(float amount) {
    if (amount > this->amount) {
        throw std::invalid_argument("Not enough money");
    }
    this->amount -= amount;
    std::cout << "Withdrew " << amount << " from " << name << std::endl;
}

void ATM::transfer(ATM* atm, float amount) {
    if (amount > this->amount) {
        throw std::invalid_argument("Not enough money");
    }
    this->amount -= amount;
    atm->deposit(amount);
    std::cout << "Transfered " << amount << " to " << atm->get_name() << std::endl;
}