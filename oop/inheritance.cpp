#include <iostream>


class Employee {
    public:
        int id;
        std::string name;
        std::string department;

    
        Employee(int id, std::string name, std::string department){
            this->id = id;
            this->name = name;
            this->department = department;
        }

        void print_smth(){
            std::cout << this->name << std::endl;
        }
};


class Manager: public Employee{
    public:
        Manager(int id, std::string name, std::string department): Employee(id, name, department){

        }
   
};  

int main(){
    Manager manage(2, "James", "Computer");
    std::cout << manage.id << std::endl;
    
}