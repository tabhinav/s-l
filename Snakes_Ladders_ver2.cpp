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
string ladder_indices[5][2] = { {"A4","B3"} ,{"C4, E6"}, {"D2, H6"} , {"E2,G1"}, {"G8,I9"}}; // INDICES ARE ALL PLACEHOLDERS
string snake_indices[5][2] = {{"J9", "A2"}, {"H7", "F6"},{"C10", "A9"},{"E10", "C8"},{"I9", "G8"}}; //INDICES ARE ALL PLACEHOLDERS
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
  /*  if ( step%6 == 0 ){
        step = step + rand()%6 + 1;
    }
    // if 3 sixes in a row, set step to zero;
    if ( step == 18 ) {
        step = 0;
    } */
    return step; 

}

//4. for going down vertically, as and when encountered by snake
string get_eaten(string loc) {
    //again, just reverse of ladder logic, will implement last
    for (int i = 0; i < 5; i++) {
            if(snake_indices[i][0] == loc) { 
                (*this).currentpos = ladder_indices[i][1];
                break;
            }
        }
     return (*this).currentpos;
}
//5. condition for winning, initially false for all, as soon as true for one, end game 
bool is_winner() {

    if((*this).currentpos == "J10") {
        cout << "Player " << (*this).name<<"Wins! " <<endl;
        return true;
    }
    return false;
}
//6
bool is_ladder(string loc) { 
    for (int i = 0; i < LAD_NO; i ++) { 
        cout<<endl;
            if(loc.compare(ladder_indices[i][0]) != 0) {
                return true;
            }
    }
    return false;
     
}
//7.
bool is_snake(string loc) { 
    for (int i = 0; i < SNAK_NO; i ++) { 
            if(snake_indices[i][0] == loc) {
                return true;
            }
    }
    return false;
     
}

 //3
string move_up_ladder(string loc) {

    for (int i = 0; i < LAD_NO; i ++) { 
            if(loc.compare(ladder_indices[i][0]) != 0) {
                this->currentpos = ladder_indices[i][1];
                break;
            }
    }
    return (*this).currentpos;
    //BEHENCHOD,  TIGHT CODE YUMMY 
}

//2. for moving horizontally across the board
string move_normal() {
    //if steps exceed ten, we will call move_up here or if ladder is encountered somewhere
    //normal moving across and up
    //we utilize coordinates to move across the board, treating it like an array
    //calling Die_count

    int step_count = Die_count();
    int val = ((*this).currentpos[1] + step_count - 48);

    if( ((*this).currentpos[0] == 'J') && val > 10 )
    {   
        cout<<"Number of steps exceeded limit. Wait for next chance"<<endl;
        return (*this).currentpos;
    }

    if(((*this).currentpos[1] + step_count - 48) > 10) {
        (*this).currentpos[0] ++; //updates letter as per ASCII numerics, so A becomes B, B becomes C, and so on. 
        int number = ((*this).currentpos[1] + step_count - 48 ) % 10;
        (*this).currentpos[1] = number + 48 ;
    }
    else {

        if( ((*this).currentpos[1] + step_count - 48) == 10)
        {
            (*this).currentpos[1] = '1';
            (*this).currentpos[2] = '0';

        }

        else
            (*this).currentpos[1]+= step_count;
    }
   // temp = temp + step_count;
    //checking if ladder location
    //if ladder, then we execute the following
    if(is_ladder((*this).currentpos)) {
        cout<<"Arrived at a ladder"<<endl;
        (*this).currentpos = move_up_ladder((*this).currentpos);
        
    }
    //if snake, then we execute the following
    else if(is_snake((*this).currentpos)) {
         cout<<"Arrived at a snake";
        (*this).currentpos = get_eaten((*this).currentpos);
    }
  
    
    return (*this).currentpos;
}

 // for moving up vertically, using ladder --> might combine move_up() and move_ladder() later on idk, yes just combine

//4. for going down vertically, as and when encountered by snake
/* string get_eaten(string loc) {
    //again, just reverse of ladder logic, will implement last
    for (int i = 0; i < 5; i++) {
            if(snake_indices[i][0] == loc) { 
                (*this).currentpos = ladder_indices[i][1];
                break;
            }
        }
     return (*this).currentpos;
}
//5. condition for winning, initially false for all, as soon as true for one, end game 
bool is_winner() {

    if((*this).currentpos == "J10") {
        cout << "Player " << (*this).name<<"Wins! " <<endl;
        return true;
    }
    return false;
}
//6
bool is_ladder(string loc) { 
    for (int i = 0; i < LAD_NO; i ++) { 
            if(ladder_indices[i][0] == loc) {
                return true;
            }
    }
    return false;
     
}
//7.
bool is_snake(string loc) { 
    for (int i = 0; i < SNAK_NO; i ++) { 
            if(snake_indices[i][0] == loc) {
                return true;
            }
    }
    return false;
     
} */



};

int main() { 

    srand(time(0));  
    const int n = 2; 
    cout << " Welcome to SNAKES AND LADDERS ! " << endl;
    //array of type player
    player player_arr[n];
    cout << "player details" << endl;
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
        cout << player_arr[i].name << endl <<" Position:  ";
        cout << player_arr[i].symb << endl << " Currentpos: ";
        cout << player_arr[i].currentpos << " ";
        cout << player_arr[i].win_status << " " <<endl;
     }
    cout << endl;
    cout << "Players go turn by turn, game begins now" << endl;
    //loop runs, calling players turn by turn, till one of them hits 
    bool cond = false;
    //do {
        for ( int i = 0 ; i < n ; i++) {
          //  player_arr[i].Die_count();
            player_arr[i].move_normal();
            cond = player_arr[i].is_winner();
            cout<<player_arr[i].name<<" is at position " <<player_arr[i].currentpos<<endl;
            //checking to see if any player won
            //exits loop if cond is true 
            if(cond == true) {
                cout << "Player " << i+1 << "Wins! GAME OVER!!!" << endl;
                break;
            }

        }
    // } while ( cond == false);
    return 0;
}
