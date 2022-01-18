#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cmath>
#include<time.h>
#include <stdlib.h>



using namespace std;
//MAX NUMBER OF STEPS = 17, MIN NUMBER OF STEPS = 0;
//global variables
//we utilize coordinates to move across the board, treating it like an array
//the board is an array of chars or strings? idk either one should work 
//char BOARD_MAT[10][10]; // size might change, we'll see.
//we will also make an array of type Player, ARRAY MIND YOU, not vector
//IMPORTANT INFO HERE
//WE WILL STORE LADDER BEGINNING INDICES IN AN ARRAY AND SNAKEHEAD INDICES IN ANOTHER ARRAY
//MAX NUMBER OF STEPS = 17, MIN NUMBER OF STEPS = 0;
//global variables
//we utilize coordinates to move across the board, treating it like an array
//the board is an array of chars or strings? idk either one should work 
//const char BOARD_MAT[10][10];// size might change, we'll see.
const int LAD_NO = 5; // number of ladders;
const int SNAK_NO = 5; // number of snakes;
string ladder_indices[5][2] = { {"A4 ","B3 "} ,{"C4 ", "E6 "}, {"D2 ", "H6 "} , {"E2 ","G1 "}, {"G8 ","I9 "}}; // INDICES ARE ALL PLACEHOLDERS
string snake_indices[5][2] = {{"J9 ", "A2 "}, {"H7 ", "F6 "},{"C10 ", "A9 "},{"E10 ", "C8 "},{"I9 ", "G8 "}}; //INDICES ARE ALL PLACEHOLDERS
//we will also make an array of type Player, ARRAY MIND YOU, not vector
//declaring member functions
//0.Die function, value ranging from 1 to 6, when 6 comes, give another chance, if 6 comes three times, assign zero
//using formula int step = rand()%(max-min + 1) + min;

class player {
//declaring data members

public:
string name;         //stores the player's name
string symb;          //stores the player's symbol as will be displayed on the board
string currentpos;  //stores the location of the player in the form of "A9", "B4" for example: currentpos[0] = letter, currentpos[1] = number, currentpos[2] = number;
bool win_status;    //whether or not player has won, false initially for all

player() {
    
    name = "Sunil";
    symb = 'R';
    currentpos = "A1 ";
    win_status = false;


}

//declaring member functions 
//1

int Die_count() {

    int step = rand()%6 + 1;
    //checking to see if multiple of 6, then
    if ( step%6 == 0 ){
        step = step + rand()%6 + 1;
    }
    // if 3 sixes in a row, set step to zero;
    if ( step == 18 ) {
        step = 0;
    } 
    return step; 

}

string move_up_ladder(string loc) {

    string posit = (*this).currentpos;
    for (int i = 0; i < LAD_NO; i ++) { 
            if(loc.compare(ladder_indices[i][0]) == 0) {
                posit = ladder_indices[i][1];
                break;
            }
    }
    return posit;
    //BEHENCHOD,  TIGHT CODE YUMMY 
}

//4. for going down vertically, as and when encountered by snake
string get_eaten(string loc) {
    //again, just reverse of ladder logic, will implement last
    string posit = (*this).currentpos;
    for (int i = 0; i < 5; i++) {
            if(loc.compare(snake_indices[i][0]) == 0) { 
                posit = snake_indices[i][1];
                break;
            }
        }
     return posit;
}
//5. condition for winning, initially false for all, as soon as true for one, end game 
bool is_winner() {

    string posit = (*this).currentpos;
    if((posit == "J10") {
        cout << "Player " << (*this).name<<"Wins! " <<endl;
        return true;
    }
    return false;
}
//6
bool is_ladder(string location) { 
    for (int i = 0; i < LAD_NO; i ++) { 
            if(location == (ladder_indices[i][0])) {
                return true;
            }
    }
    return false;
     
}
//7.
bool is_snake(string loc) { 
    for (int i = 0; i < SNAK_NO; i ++) { 
            if(loc.compare(snake_indices[i][0]) == 0) {
                return true;
            }
    }
    return false;
     
}


//2. for moving horizontally across the board
string move_normal() {
    //if steps exceed ten, we will call move_up here or if ladder is encountered somewhere
    //normal moving across and up
    //we utilize coordinates to move across the board, treating it like an array
    //calling Die_count

    int step_count = Die_count();
   // cout<<"DIE COUNT "<<step_count<<" Old position" <<(*this).currentpos<<endl;
    string posit = (*this).currentpos;
    int val = (posit[1] + step_count - 48);

    if( (posit[0] == 'J') && val > 10 )
    {   
        cout<<"Number of steps exceeded limit. Wait for next chance"<<endl;
        return posit;
    }

    if(posit[1] == '1' && posit[2] == '0')
    {
        posit[0] ++;
        posit[1] = step_count + 48;
        posit[2] = ' ';

    }

    else if((posit[1] + step_count - 48) > 10 ) {
        (posit[0] ++; //updates letter as per ASCII numerics, so A becomes B, B becomes C, and so on. 
        int number = (posit[1] + step_count - 48 ) % 10;
        posit[1] = number + 48 ;
    }
    else {

        if( (posit[1] + step_count - 48) == 10)
        {
            posit[1] = '1';
            posit[2] = '0';

        }

        else {
            posit[1]+= step_count;
        }
    }
   // temp = temp + step_count;
    //checking if ladder location
    //if ladder, then we execute the following
    if(is_ladder(posit) {
        cout<<" Arrived at a LADDER "<<endl;
        posit = move_up_ladder(posit);
        
    }
    //if snake, then we execute the following
    if(is_snake(posit) {
         cout<<"Arrived at a SNAKE"<<endl;
        posit = get_eaten(posit);
    }
  
    
    return posit;
}


};

int main() { 

    srand(time(0));  
    int n = 0; 
    int flag = 1;
    cout << "Welcome to SNAKES AND LADDERS ! " << endl;
    cout<<"To roll the die, press 1"<<endl;
    cout<<"If you want to quit the game, press 0"<<endl;
    while(true)
        {
    cout<<"How many players are playing (maximum 4, minimum 2)"<<endl;
    cin>>n;
        if(n>1 && n<5)
            break;
        }
    //array of type player
    player player_arr[n];

    cout << "Enter Player Details" << endl;
    for (int i = 0; i < n ; i++) { 
        cout << "Enter player "<<i+1<<" name ";
        cin>> player_arr[i].name;
        cout << "Enter symbol/color "<<i+1<<" ";
        cin>> player_arr[i].symb;
        cout << endl;
    }

    cout << "Displaying player info " << endl;
    for (int i = 0; i < n; i++) { 
        cout << "Player" << i+1 <<endl << " Name: ";
        cout << player_arr[i].name << endl <<" Position: ";
        cout << player_arr[i].symb << endl << " Currentpos: ";
        cout << player_arr[i].currentpos << " "<<endl;
     }
    cout << endl;
    cout << "Players go turn by turn, game begins now" << endl;
    //loop runs, calling players turn by turn, till one of them hits 
    cout<< "Do you want to roll the die"<<endl;
    cin>>flag;

    bool cond = false;
    do {
        for ( int i = 0 ; i < n ; i++) {
          //  player_arr[i].Die_count();
            player_arr[i].move_normal();
            cond = player_arr[i].is_winner();
            cout<<player_arr[i].name<<" is at position " <<player_arr[i].currentpos<<endl;
            //checking to see if any player won
            //exits loop if cond is true 

           // cout<<" Do you wanna roll again" <<endl;
            //cin>>flag;

            if(cond == true) {
                cout << "Player " << i+1 << "Wins! GAME OVER!!!" << endl;
                break;
            }
        }

     } while ( cond == false && flag > 0);
    return 0;
}
