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

int BankAccount::number = 0;

BankAccount::BankAccount(std::string name, std::string account_t, double balance, double interest_rate){
    this->name = name;
    this->balance = balance;
    this->interest_rate = interest_rate;
    this->account_number = number;
    number++;
    while (account_t != "checking" && account_t != "saving"){
        std::cout << "Invalid account type. (Enter either 'checking' or 'saving'): ";
        getline(std::cin, account_t);
    }
    this->account_type = account_t;
}

void BankAccount::checkBalance(){
    std::cout << name << "'s balance is " << balance << std::endl;
}

double BankAccount::withdraw(double amount){
    if (amount > this->balance){
        std::cout << "Error! The amount being requested is more than the balance!\n amount: " << amount << " balance: " << this->balance << std::endl;
        return 0.0;
    }
    this->balance -= amount;
    std::cout << amount << " has been withdrawn from account.\n" << name << "'s New balance: " << this->balance << std::endl;
}

void BankAccount::deposit(double amount){
    if (amount < 0){
        std::cout << "Error! The amount to be deposited cannot be negative\n";
        return;
    }
    this->balance += amount;
    std::cout << amount << " has been deposited into the account.\n" << name << "'s New balance: " << this->balance << std::endl; 
}

void BankAccount::transfer(double amount, BankAccount& other){
    if (amount < 0){
        std::cout << "Error! The amount to be transferred cannot be negative\n";
        return;
    }
    if (amount > this->balance){
        std::cout << "Error! The amount being transferred is more than the balance!\n amount: " << amount << " balance: " << this->balance << std::endl;
        return;
    }
    this->balance -= amount;
    other.balance += amount;
    std::cout << amount << " has been sent to " << other.name << "\n" << name << "'s New balance: " << this->balance << std::endl;
}

BankAccount::~BankAccount(){
    std::cout << this->name << "'s bank account has been deleted\n";
}

int main(){
    BankAccount one("James", "checking", 0, 2);
    BankAccount two("Micheal", "saving", 0, 5);
    one.deposit(600);
    two.deposit(200);
    one.withdraw(200);
    one.transfer(200, two);
    two.checkBalance();
}
