#include <iostream>

using namespace std;


int main(){
    int matrix[3][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}
    };
    int minNum = matrix[0][0];

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            if (minNum >= matrix[i][j]){
                minNum = matrix[i][j];
            
            }
        }
    }
    
    cout << "The smallest number in the array is " << minNum << endl;

}