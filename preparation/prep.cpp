#include <iostream>
#include <vector>

void input_data(std::vector<int> &numbers);
int sorting(std::vector<int> numbers);

int main(){
    std::vector<int> numbers;
    input_data(numbers);
    std::cout << "The sum of all the even numbers in the vector is " << sorting(numbers) << std::endl;

}


void input_data(std::vector<int> &numbers){
    std::cout << "Enter 10 numbers to be entered into the vector\n";

    for (int i = 0; i < 10; i++){
        int val;
        std::cout << "Number " << i + 1 << ": ";
        std::cin >> val;
        numbers.push_back(val);
    }
}

int sorting(std::vector<int> numbers){
    int sum = 0;
    for (int i : numbers){
        if (i % 2 == 0) sum += i;
    }
    return sum;
}