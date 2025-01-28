#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct letterCount{
    char letter;
    int count;
};


int checkFile(fstream & inputFile, ofstream & outputFile);
string getFileName(string fileType);
void createStructs(letterCount counter[]);
void printResult(letterCount counter[], ofstream & outputFile);
void count(letterCount counter[], fstream & inputFile);

int main(){
    letterCount counter[52];
    createStructs(counter);
    string input = getFileName("input");
    string output = getFileName("output");
    fstream inputFile(input);
    ofstream outputFile(output);
    int res = checkFile(inputFile, outputFile);
    if (res == 1){
        return 2;
    }
    count(counter, inputFile);
    printResult(counter, outputFile);
   
}

void createStructs(letterCount counter[]){
    int index = 0;
    for (char x = 'a'; x <= 'z'; x++){
        letterCount value;
        value.letter = x;
        value.count = 0;
        counter[index] = value;
        index++;
    }
    for (char x = 'A'; x <= 'Z'; x++){
        letterCount value;
        value.letter = x;
        value.count = 0;
        counter[index] = value;
        index++;
    }
}


string getFileName(string fileType){
    string file;
    cout << "Enter the name of the " << fileType << " file: ";
    cin >> file;
    
    return file;
}

int checkFile(fstream & inputFile, ofstream & outputFile){
    if (inputFile.good() != 1){
        cout << "The input file does not exist!";
        return 1;
    }
    if (outputFile.good() != 1){
        cout << "The output file does not exist! Creating...\n";
    }
    return 0;
    
}

void count(letterCount counter[], fstream & inputFile){
    string lines;
    while (getline(inputFile, lines)){
        
        for (char character : lines){
            int pos;
            if (character >= 'a' && character <= 'z'){
                pos = character - 'a';
            }
            else if (character >= 'A' && character <= 'Z'){
                pos = character - 'A' + 26;
            }
            
            counter[pos].count ++;
        }
    }
}

void printResult(letterCount counter[], ofstream & outputFile){
    int lowerCaseCount = 0;
    int upperCaseCount = 0;
    for (int i = 0; i < 26; i++){
        lowerCaseCount += counter[i].count;
    }
    for (int i = 26; i < 52; i++){
        upperCaseCount += counter[i].count;
    }
    
    cout << "\n\nThe count of lowercase letters (a - z) and their percentages\n";
    outputFile <<"The count of lowercase letters (a - z) and their percentages\n";

    cout << "Letter" << setw(28) << "Count" << setw(30) << "Percentage\n";
    outputFile << "Letter" << setw(28) << "Count" << setw(30) << "Percentage\n";

    for (int i = 0; i < 26; i ++){
        double percent = ((double) counter[i].count/ (double) lowerCaseCount) * 100 ;
        cout << counter[i].letter << setw(30) << counter[i].count << setw(30) << percent << '%' << endl;
        outputFile << counter[i].letter << setw(30) << counter[i].count << setw(30) << percent << '%' << endl;

    }

    cout << "\n\nThe count of uppercase letters (A - Z) and their percentages\n";
    outputFile <<"\n\nThe count of uppercase letters (A - Z) and their percentages\n";

    cout << "Letter" << setw(28) << "Count" << setw(30) << "Percentage\n";
    outputFile << "Letter" << setw(28) << "Count" << setw(30) << "Percentage\n";

    for (int i = 26; i < 52; i ++){
        double percent = ((double) counter[i].count/ (double) upperCaseCount) * 100;
        cout << counter[i].letter << setw(30) << counter[i].count << setw(30) << percent << '%' << endl;
        outputFile << counter[i].letter << setw(30) << counter[i].count << setw(30) << percent << '%' << endl;
    }
    
    
}