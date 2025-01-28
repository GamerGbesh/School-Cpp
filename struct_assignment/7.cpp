#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

enum selection{
    EXIT = 0,
    SHOWALLPLAYERS,
    SEARCHBYINDEX,
};


struct playDeets {
    string name;
    string position;
    int numberOfTouchdowns;
    int numberOfCatches;
    int numberOfPassingYards;
    int numberOfReceivingYards;
    int numberOfRushingYards;
};


const int N = 10;
playDeets players[N];

void inputData();
void outputData();
void searchByIndex();

int main(){
    inputData();
    int choice;
    do {
        cout << "\nMenu\n" << string(60, '-') << endl;
        cout << "1. Show all players\n";
        cout << "2. Search for player by index\n";
        cout << "0. Exit\n\n";

        cout << "What is your choice: ";
        
        cin >> choice;
        switch (choice){
            case EXIT:
                char userChoice;
                cout << "Do you want to export the information to a file (y/n): ";
                cin >> userChoice;
                if (userChoice == 'y' || userChoice == 'Y'){
                    ofstream playerFile("Players.txt");
                    int number = 28;
                    playerFile << "Name" << setw(number) << "Position" << setw(number) << "Number of Catches" << setw(number) << "Number of Passing Yards" << setw(number)
                    << "Number of Receiving Yards" << setw(number) << "Number of Rushing Yards\n"; 
                    playerFile << string(155, '-') << endl;
                    for (playDeets player : players){
                        playerFile << player.name << setw(number - player.name.size()) << player.position << setw(number - player.position.size()) << player.numberOfCatches << setw(number) << player.numberOfPassingYards << setw(number)
                    << player.numberOfReceivingYards << setw(number) << player.numberOfRushingYards << endl;
                    } 
                }
                break;
            case SHOWALLPLAYERS:
                outputData();
                break;
            case SEARCHBYINDEX:
                searchByIndex();
                break;
        }
    } while (choice != EXIT);
}


void inputData(){
    for (int i = 0; i < N; i++){
        cout << "Player " << i + 1 << endl;
        cout << "What is the player's name: ";
        getline(cin, players[i].name);
        cout << "What position does he/she play: ";
        getline(cin, players[i].position);
        cout << "Player's number of catches: ";
        cin >> players[i].numberOfCatches;
        cout << "Player's number of passing yards: ";
        cin >> players[i].numberOfPassingYards;
        cout << "Player's number of receiving yards: ";
        cin >> players[i].numberOfReceivingYards;
        cout << "Player's number of rushing yards: ";
        cin >> players[i].numberOfRushingYards;
        cin.ignore();
    }
    
    cout << endl;
}

void outputData(){
    int number = 28;
    cout << "Name" << setw(number) << "Position" << setw(number) << "Number of Catches" << setw(number) << "Number of Passing Yards" << setw(number)
    << "Number of Receiving Yards" << setw(number) << "Number of Rushing Yards\n"; 
    cout << string(155, '-') << endl;
    for (playDeets player : players){
        cout << player.name << setw(number - player.name.size()) << player.position << setw(number - player.position.size()) << player.numberOfCatches << setw(number - to_string(player.numberOfCatches).size()) << player.numberOfPassingYards << setw(number- to_string(player.numberOfPassingYards).size())
    << player.numberOfReceivingYards << setw(number - to_string(player.numberOfReceivingYards).size()) << player.numberOfRushingYards << endl;
    }
}

void searchByIndex(){
    int index;
    cout << "Index of player you want to search: ";
    cin >> index;
    index --;
    cout << "Name: " << players[index].name << endl;
    cout << "Position: " << players[index].position << endl;
    cout << "Catches: " << players[index].numberOfCatches << endl;
    cout << "Number of Passing Yards: " << players[index].numberOfPassingYards << endl;
    cout << "Number of Receiving Yards: " << players[index].numberOfReceivingYards << endl;
    cout << "Number of Rushing Yards: " << players[index].numberOfRushingYards << endl;
    cin.ignore();

    char choice;
    cout << "\nDo you want to edit this information (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y'){
        cout << "What is the player's name: ";
        getline(cin, players[index].name);
        cout << "What position does he/she play: ";
        getline(cin, players[index].position);
        cout << "Player's number of catches: ";
        cin >> players[index].numberOfCatches;
        cout << "Player's number of passing yards: ";
        cin >> players[index].numberOfPassingYards;
        cout << "Player's number of receiving yards: ";
        cin >> players[index].numberOfReceivingYards;
        cout << "Player's number of rushing yards: ";
        cin >> players[index].numberOfRushingYards;
        cin.ignore();
    }
}