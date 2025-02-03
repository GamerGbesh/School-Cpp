#ifndef ATM_H
#define ATM_H

#include <iostream>

class ATM{
private:
    float amount;
    std::string name;
public:
    ATM(std::string);
    float show_balance() const;
    std::string get_name() const;
    void set_amount(float);
    void set_name(std::string);
    void deposit(float);
    void withdraw(float);
    void transfer(ATM *, float);
};

#endif