// Name: Mensah Philemon Edem Yao
// Id: 22042860

#include <iostream>

using namespace std;
int main(){
    
    int row = 8;
    int col = 8;
    char xo[] = {'O', 'X'};
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cout << xo[j % 2];
        }
        char temp = xo[0];
        xo[0] = xo[1];
        xo[1] = temp; 
        cout << endl;  
    }           
}