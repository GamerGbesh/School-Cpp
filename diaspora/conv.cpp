#include <iostream>

using namespace std;

int main(){
    string name = "Hello!";
    int age = 7;
    string alpha = "abcdefghijklmnopqrst";
    cout << age << endl;
    cout << name.at(3) << endl;
    cout <<  alpha.find("efg", 3) << endl;

    cout << alpha.substr(6, 6) << endl;
    
    string a = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    int num = 0;
    for (int i = 0; i<a.length(); i++){
       int found = a.find("aaa", i);
       if (found < 1000){
            num++;
       }
    }
    cout << "The number of aaa sequence in string a is "<< num << endl;
}