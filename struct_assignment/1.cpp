#include <iostream>

using namespace std;

int main(){

    struct fruitType {
        string name;
        string color;
        int fat;
        int sugar;
        int carbohydrate;
    };

    string name;
    string color;
    int fat;
    int sugar;
    int carbohydrate;
    fruitType fruit;

    cout << "Enter the name of the fruit: ";
    cin >> name;
    cout << "Enter the color of the fruit: ";
    cin >> color;
    cout << "Enter the fat of the fruit: ";
    cin >> fat;
    cout << "Enter the sugar level of the fruit: ";
    cin >> sugar;
    cout << "Enter the carbohydrates level of the fruit: ";
    cin >> carbohydrate;

    fruit.name = name;
    fruit.color = color;
    fruit.fat = fat;
    fruit.sugar = sugar;
    fruit.carbohydrate = carbohydrate;

    cout << endl;

    cout << "The name of the fruit is " << fruit.name << endl;
    cout << "The color of the fruit is " << fruit.color << endl;
    cout << "The fat level of the fruit is " << fruit.fat << endl;
    cout << "The sugar level of the fruit is " << fruit.sugar << endl;
    cout << "The carbohydrate level of the fruit is " << fruit.carbohydrate << endl;
}