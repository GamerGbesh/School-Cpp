#include <iostream>
using namespace std;

int main(){
    for (int i = 1; i < 20; i+=2){
        if(i == 11){
            continue;
        }
        cout << i << " ";
    }
    cout << endl;

    int arr[] = {0, 1, 2, 1, 4, 2, 3, 2};
    for (int i = 0;  i < sizeof(arr)/ sizeof(arr[0]); i++){
        if (arr[i] == 2){
            cout << i;
            cout << endl;
            break;
        }
    }

    cout << arr[1]<< endl;

    for (int i = 10; i >= 0; i--){
        cout << i << " ";
    }
    cout << endl;
    int number = 10;
    while (number >= 0){
        cout << number << " ";
        number--;
    }
    cout << endl;
    for (int i = 0; i < 7; i++){
        for (int j = 0; j < 5; j++){
            cout << "#";
        }
        cout << endl;
    }
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            char op = i % 2 ? '<' : '>';
            cout << op;
        }
        cout << endl;

    }
    
    for (int i = 1; i < 8; i++){
        for (int j = 0; j < i; j++){
            cout << i << " ";
        }
        cout << endl;
    }

}