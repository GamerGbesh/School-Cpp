#include <iostream>
#include <string>

class BankAccount{
    static int number;
    std::string name;
    int account_number;
    std::string account_type;
    double balance;
    double interest_rate;

    public:
        BankAccount(std::string name, std::string account_type, double balance, double interest_rate);
        void checkBalance();
        double withdraw(double amount);
        void deposit(double amount);
        void transfer(double amount, BankAccount& other);
        ~BankAccount();

};