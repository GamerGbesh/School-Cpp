#include <vector>
#include <iostream>


/* Array size can't be changed
   A vector can be used if you want a create an array that can be changed
*/

using namespace std;

int main(){
    vector<int> age = {0, 2, 3, 4};
    age.push_back(3); // Add an element to the back of the vector
    age.push_back(6); 
    age.insert(age.begin() + 1, 100); // Add an element to any index in the vector
    age.pop_back(); // Remove the last element in a vector
    age.erase(age.begin() + 3); // Remove an element at a specific index
    for (int i = 0; i < age.size(); i++){
        cout << age.at(i) << " ";
    }
    cout << endl;
    // int i = 0;
    // while (i != age.size()){
    //     cout << age.at(i) << " ";
    //     i++;
    // }
    // cout << endl;
    // i = 0;
    // while (i < 5){
    //     cout << i<< endl;
    //     ++i;
    // }
    //  i = 0;
    // while (i < 5){
    //     cout << i<< endl;
    //     i++;
    // }
    cout << endl;
    vector<vector<int>> name{{1, 2, 3, 4}, 
                            {5, 6, 7, 8}, 
                            {9, 10 , 11, 12}};
    int number = 0;
    for(int i = 0; i < name.size(); i++){
        for (int j = 0; j < name.at(i).size(); j++){
            cout << name.at(i).at(j) << " ";
            number++;
        }
        cout << endl;
    }
    cout << number;
     
    /*The index of the vector can be checked either by using the .at() method on the vector or by using the [] indexing
    The .at() method throws an error if the index is out of range but the [] indexing does not throw an error if it is out of range
    */ 
}