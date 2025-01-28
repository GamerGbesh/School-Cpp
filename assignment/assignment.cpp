#include <iostream>
#include <ctime>
#include <math.h>
using namespace std;

void doubleNum(int (&arr)[], int &size);
void reverseNum(int (&arr)[], int &size);
void raiseNum(int (&arr)[], int &size);
int sumNum(int (&arr)[], int &size);
int firstNumPowSecondNum(int (&arr)[], int &size);

typedef int two_positive_rand_digits;

int main(){

    srand(time(NULL));

    two_positive_rand_digits posNum[] = {rand() % 9 + 1 , rand() % 9 + 1};
    
    int size = sizeof(posNum)/sizeof(posNum[0]);
    

    cout <<"Random number = ";

    for(int i = 0; i < size; i++){
        cout <<posNum[i];
    }
    cout <<'\n' <<"Double of num = "; 
    doubleNum(posNum,size);

    cout <<'\n' <<"Reverse of num = ";
    reverseNum(posNum, size);

    raiseNum(posNum, size);

    cout <<"\nSum of digitis = " << sumNum(posNum,size) <<'\n';

    cout <<"First number raised to the second number = " << firstNumPowSecondNum(posNum, size) <<endl;
    return 0;
}

void doubleNum(int (&arr)[], int &size){
    string s1;
    for(int i=0; i < size; i++){
      s1+= to_string(arr[i]);  
    }
    int num = stoi(s1);
    // cout << num *2;
    num *=2;
    string s2 = to_string(num);
    for(int i = 0; i < s2.size(); i++){
        arr[i] = (int)(s2[i]-'0');
        cout <<arr[i];
        if(i == s2.size()-1){
            size = s2.size();
        }
    }
    

}

void reverseNum(int (&arr)[], int &size){
    int temp;
    if(size == 2){
        temp = arr[0];
        arr[0] = arr[1];
        arr[1] = temp;
    }
    else{
        temp = arr[0];
        arr[0] = arr[2];
        arr[2] = temp;
    }
    for(int i = 0; i < size; i++){
        cout <<arr[i];
    }
    

}

void raiseNum(int (&arr)[], int &size){
    string s1;
    for(int i = 0; i < size; i++){
        s1 += to_string(arr[i]);
    }
    int num = stoi(s1);
    int num1 = (rand() % 3) + 2;
    long powNum = pow(num,num1);
    cout <<"\n" <<powNum <<"\n";

    string s2 = to_string(powNum);

    for(int i = 0; i < s2.size(); i++){
        arr[i] = (long)(s1[i] - '0');
        cout <<arr[i] <<" ";
        if(i == s2.size()-1){
            size = s2.size();
        }
    }
}

int sumNum(int (&arr)[], int &size){
    int num = arr[0];
    for(int i=0; i < size; i++){
        if(i == 0)
        continue;;
        num += arr[i];
    }
    return num;
}

int firstNumPowSecondNum(int (&arr)[], int &size){
    int num;
    if(size == 2){
        num = pow(arr[0],arr[1]);
    }
    return num;
}