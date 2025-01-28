
#include <iostream>
using namespace std;

int main(){
    string sentence;
    int lowerCases = 0;
    int upperCases = 0;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    for (int i = 0; i < sentence.length(); i++){
        if (isupper(sentence[i]) != 0){
            upperCases++;
        }
        else if (islower(sentence[i]) != 0){
            lowerCases++;
        }
    }
    cout << "Number of uppercase letters: " << upperCases << endl;
    cout << "Number of lowercase letters: " << lowerCases << endl;
    
}
