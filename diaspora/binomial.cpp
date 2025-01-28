#include <iostream>
#include <vector>
using namespace std;

int factorial(int n){
    if (n<0)
    return(-1);
    if(n==0)
    return(1);
    else{
        return(n*factorial(n-1));
    }
}

vector<int> combination(int num){
    int coefficient = 0;
    vector<int> any;
    for(int i = 0; i <= num; i++){
        coefficient = factorial(num)/(factorial(num -i) * factorial(i));
        any.push_back(coefficient);
    }
    return any;
}

void printBinomialTriangle(int num){
    for(int i = 0; i <= num; i++){
        for(auto j: combination(i)){
            cout <<j <<" ";
        }
        cout <<'\n';
    }
}
int main(){
    printBinomialTriangle(4);
}