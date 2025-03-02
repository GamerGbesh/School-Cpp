#include <iostream>

int main(){

    std::string hello = "hello";
    try{
        int fin = std::stoi(hello);
    }
    catch (std::invalid_argument){
        std::cout << "This operation cannot be completed";
    }
    

}