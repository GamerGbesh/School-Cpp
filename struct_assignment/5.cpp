#include <iostream>
#include <vector>
#include <iomanip>
#include <unordered_map>
#include <string>

using namespace std;

struct menuItemType{
        string menuItem;
        double menuPrice;
    };

void getData(menuItemType *array, int size);
vector<menuItemType> showMenu(menuItemType *array, int size);
void printCheck(vector<menuItemType> items, menuItemType menu[]);

int main(){
    cout << fixed << setprecision(2);
    const int numberOfItems = 8;
    menuItemType menu[numberOfItems];
    getData(menu, numberOfItems);
    vector<menuItemType> items = showMenu(menu, numberOfItems);
    printCheck(items, menu);
}


void getData(menuItemType *array, int size){
    array[0].menuItem = "Plain Egg";
    array[0].menuPrice = 1.45;
    array[1].menuItem = "Bacon and Egg";
    array[1].menuPrice = 2.45;
    array[2].menuItem = "Muffin";
    array[2].menuPrice = 0.99;
    array[3].menuItem = "French Toast";
    array[3].menuPrice = 1.99;
    array[4].menuItem = "Fruit Basket";
    array[4].menuPrice = 2.49;
    array[5].menuItem = "Cereal";
    array[5].menuPrice = 0.69;
    array[6].menuItem = "Coffee";
    array[6].menuPrice = 0.50;
    array[7].menuItem = "Tea";
    array[7].menuPrice = 0.75;
}

vector<menuItemType> showMenu(menuItemType *array, int size){
    

    cout << "\n\nWelcome to my restaurant\n";
    cout << "Choose your item based on their numbers\nPress enter after each selection to select multiple.\n0 to submit order!\n\n";
    for (int i = 0; i < size; i++){
        int spacing = 40;
        int sizeOfString = array[i].menuItem.size();
        spacing = spacing - sizeOfString;
        cout << i+1 << ". " << array[i].menuItem << setw(spacing) << '$' <<array[i].menuPrice << endl;
    }
    int userChoice;
    cout << "\nMake your selections!\n";
    vector<menuItemType> items;
    while (true) {
        cin >> userChoice;
        if (userChoice > size || userChoice < 0){
            cout << "Invalid Choice, choose again\n";
            continue;
        }
        if (userChoice == 0){
            break;
        }
        items.push_back(array[userChoice-1]);
    }
    return items; 
}

void printCheck(vector<menuItemType> items, menuItemType menu[]){
    cout << "\nCheck:\n";
    cout << "Item" << setw(35) << "Quantity" << setw(29) << "Price\n";
    cout << string(120, '-') << endl;
    double totalPrice = 0;
    double totalTax = 0;
    unordered_map<string, int> orders;
    

    for (menuItemType item : items){
        if (orders.count(item.menuItem) > 0){
            orders[item.menuItem] += 1;
        }
        else{
            orders[item.menuItem] = 1;
        }
    }
    for (auto p : orders){
        double price;
        for (int i = 0; i < 8; i++){
            if (p.first == menu[i].menuItem) price = menu[i].menuPrice;
        }
        int spacing1 = 35 - p.first.size();
        string priceS = to_string(price);
        int spacing2 = 35 - priceS.size();
        double tax = price * 0.05;
        cout << p.first << setw(spacing1) << p.second << setw(spacing2) << '$' << price * p.second << endl;
        totalPrice += price * p.second;
        totalTax += tax;
    }

    
    cout << string(120, '-') << endl;
    string price = to_string(totalPrice);
    cout << "Tax: " << '$' << totalTax << endl;
    cout << "Total: " << totalPrice + totalTax << endl;

}
