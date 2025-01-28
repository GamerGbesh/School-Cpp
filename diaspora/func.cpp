#include <iostream>
#include <vector>

using namespace std;

void hello_twice();
int add(int a, int b);
int multiply(int a, int b);
int subtract(int a, int b);
int divide(int a, int b);
int find_min_vec(vector<int> numbers);
int find_min_arr(int* numbers, int size);


int main(){
    hello_twice();
    cout << add(2, 3) << endl;
    vector<int> numbers = {9, 4, 6, 1, 6};
    int arr[] = {9, 4, 6, 1, 6};
    cout << find_min_vec(numbers) << endl;
    cout << find_min_arr(arr, sizeof(arr)/sizeof(arr[0]));
}


void hello_twice(){
    cout << "Hello"<< endl;
    cout << "Hello"<< endl;
    return;
}

int add(int a, int b){
    return a + b;
}


int subtract(int a, int b){
    return a - b;
}


int divide(int a, int b){
    return a / b;
}


int multiply(int a, int b){
    return a * b;
}


int find_min_arr(int* numbers, int size){
    int nums[size]; 
    for (int i = 0; i < size; i++){
        nums[i] = numbers[i];
        
    }
    int minimum = nums[0];

    for (int i = 0; i < sizeof(nums)/ sizeof(nums[0]); i++){
        if (nums[i] < minimum){
            minimum = nums[i];
        }
    }
    return minimum;
}

int find_min_vec(vector<int> numbers){
    int minimum = numbers[0];
    for (int i = 0; i < numbers.size(); i ++){
        minimum = numbers.at(i) < minimum ? numbers.at(i) : minimum;
    }
    return minimum;
}