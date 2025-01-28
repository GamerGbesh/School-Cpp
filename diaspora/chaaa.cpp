#include <iostream>
using namespace std;

int count(string sentence){
    int x = 0; //count = 0;
    for (char letter : sentence){
        x++;
    }
    return x;
}

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    cout << count(sentence) << endl;
}

