#include <iostream>
#include <fstream>
using namespace std;

class Dog{
    private:
        void bark(){
            cout <<"Woof!\n";
        };
    public:
        void speak(){
            bark();
        };
};

int main(){
    fstream myfile;
    myfile.open("whatever.txt", ios::out);
    if (myfile.is_open()){
        cout << "The file is open\n";
        myfile << "This is the first file that we are working with\n";
        myfile << "I am a boy\n";
    }    
    else{
        cout << "The file is not open\n";
    }
    myfile.close();


    fstream file;
    file.open("whatever.txt", ios::in);
    string text;
    if (file.is_open()){
        while(getline(file, text)){
        cout << text << endl;
        }
        file.close();
    }
    Dog dog;
    dog.speak();
}