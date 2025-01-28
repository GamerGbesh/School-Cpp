#include <iostream>
#include <vector>

using namespace std;

struct studentType{
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};
const int N = 20;

studentType students[N];

void getDetails();
char checkGrade(int score);
int highestScore();
void highestScoringStudents(int score);
void printStudents();

int main(){
    getDetails();
    printStudents();
    int maxScore = highestScore();
    highestScoringStudents(maxScore);

}

void getDetails(){
    for (int i = 0; i < N; i++){
        string studentFName;
        string studentLName;
        int testScore;
        cout << "Student " << i + 1 << endl;
        cout << "Enter Student's First Name: ";
        cin >> studentFName;
        cout << "Enter Student's Last Name: ";
        cin >> studentLName;
        do {
            cout << "Enter Student's Test Score: ";
            cin >> testScore;
            if (testScore < 0 || testScore > 100){
                cout << "The test score should be in the range 1 - 100 inclusive\n";
            }
        } while (testScore < 0 || testScore > 100);
        
        char grade = checkGrade(testScore);
        students[i].studentFName = studentFName;
        students[i].studentLName = studentLName;
        students[i].testScore = testScore;
        students[i].grade = grade;
    }
}

void printStudents(){
    cout << "Names of all the students\n";
    for (studentType student : students){
        cout << student.studentLName << ", " << student.studentFName << endl;
    }
}

char checkGrade(int score){
    if (score > 80){
        return 'A';
    }
    else if (score > 70){
        return 'B';
    }
    else if (score > 60){
        return 'C';
    }
    else if (score > 50){
        return 'D';
    }
    else{
        return 'F';
    }
}

int highestScore(){
    int maxScore = 0;
    for (int i = 0; i < N; i++){
        maxScore = (maxScore < students[i].testScore) ? students[i].testScore : maxScore;
    }
    return maxScore;
}

void highestScoringStudents(int score){
    vector<studentType> highscore;
    for (int i = 0; i < N; i++){
        if (students[i].testScore == score){
            highscore.push_back(students[i]);
        }
    }
    cout << "The students that got the highest score in the test (" << score <<"):" << endl;
    for (studentType student : highscore){
        cout << student.studentLName << " " <<student.studentFName << endl;
    }
}