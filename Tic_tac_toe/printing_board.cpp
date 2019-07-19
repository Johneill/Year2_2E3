//
//  printing board.cpp
//  
//
//  Created by David Neill on 09/10/2017.
//
//

#include "printing board.hpp"
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

const int board_height = 3;
const int board_width = 3;
const int WINNING_SEQUENCE = 3;

const int BLANK   = 0;
const int player1 = 1;
const int player2 = 2;

const char GAME_TOKENS[] = {' ','X','O'};
int array_1[3][3];


void print_board ();
char fill_array1(char array_1[3][3]);


int main () {
    
    int player;
    int sequence = 1;
    int x,y;
    bool gameover = false;
    char array_1[3][3];
    char h;
    
    
    array_1[0][0] = h ;
    cout << array_1[0][0];
    
    print_board();
    fill_array1(array_1);
    print_board();
    
    array_1[0][0] = h ;
    cout << array_1[0][0];
    
    player = player1;
    while (!gameover){
        if (sequence % 2 ==0){
            player = player2;
        } else player = player1;
        
        
        
        cout << "please enter the coordinates you wish to place your letter player " << player;
        cin >> x >> y;
        
        while(array_1[x][y]==0){
            cout<< player;
            
            
        }
        cout << "This square is already full pick another one";
        
        
        
        
        sequence ++;
        
        
    }
    


    
    
    
    
    return 0;
}

void print_board(){
    int x=0;
    int y=0;
    for (y=0;y<board_height-1; y++){
        cout << "_" << array_1[x][y] <<"_";
        for(x=0; x<board_width-1; x++){
            cout << "|_" << array_1[x][y] << "_";
        }
        cout << endl;
    }
    for (y=3;y==3;y++){
        for(x=0; x<2; x++){
            cout  << "   |";
        }
        cout << endl;
    }
}

char fill_array1(char array_1[3][3]){
    
    int x,y;
    char b;
    char _;
    
    b=_;
    
    for (y=0;y<3; y++){
        for(x=0; x<3; x++){
            array_1[x][y]= 5 ;
            
            
        }
    }
    return 0;

}
