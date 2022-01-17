#include <stdio.h>
#include <cmath>
#include <iostream>
using namespace std;

//const int DIM = 2;
int main() { 

    //output of snakes and ladders board
    
    for (int i = 0 ; i < 3 ; i++ ) { 
        for ( int j = 0 ; j < 4; j++ ) {
            if(i%2 == 0) {
                cout << "#";
            }
            else {
                cout << "#";
                j = j+3;
            }

            }
        cout<<endl;

       }
    return 0;
}
