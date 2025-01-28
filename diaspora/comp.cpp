#include <iostream>

using namespace std;

int main(){
    string one;
    string two;
    cout << "Enter the first string\n";
    getline(cin, one);
    cout << "Enter the second string\n";
    getline(cin, two);
    int compare = one.compare(two);
    if (compare == 0){
        cout << "The strings are the same" << endl;
    }
    else if (compare == -1){
        cout << "The first string is smaller"<< endl;
    }
    else{
        cout << "The second string is smaller" << endl;
    }
    
}