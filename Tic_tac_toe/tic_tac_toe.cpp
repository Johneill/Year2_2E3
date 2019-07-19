//
//  tic_tac_toe.cpp
//  
//
//  Created by David Neill on 10/10/2017.
//
//
#include <iostream>
#include <cmath>


using namespace std;

const int player1 = 1;
const int player2 = 2;
const char a = '-';
const char x = 'X';
const char o = 'O';
void printBoard(char **b, int r, int c);
void printBoard2(char**b, int r, int c);



int main() {
    
    int c;
    int r;
    bool gameover = false;
    int sequence = 1;
    int player;
    int d, e;
    cout << "how many columns and rows do you want" << endl;
    cin >> c;
    cout << endl;
    r = c;
    
    
    
    char**board; // repeat this to delete other way
    board = new char*[r];
    for (int i = 0;i<r;i++)
        board[i] = new char[c];
    
    //cout << c;
    
    
    for (int y = 0; y < c; y++) {
        for (int x = 0; x < r; x++) {
            board[x][y] = a;
            //cout << board[x][y];
        }
    }
    printBoard(board, r, c);
    
    while (!gameover) {
        
        player = player1;
        if (sequence % 2 == 0) {
            player = player2;
        }
        else player = player1;
        
        cout << "player " << player << " to go, please enter co-ordinates of" << endl;
        
        cin >> e >> d;
        
        if (board[e][d] =='-' && player == player1) {
            board[e][d] = x;
            
        }
        //else cout << "This place is full pick another place";
        
        if (board[e][d] == '-' && player == player2) {
            board[e][d] = o;
            
        }
        //else cout << "This place is full pick another place";
        
        
        printBoard2(board, r, c);
        
        
        
        
        
        sequence++;
    }
    
    
    
    
    
    return 0;
}

void printBoard(char**b, int r, int c) {
    
    for (int i = 0; i < 1; i++) {
        cout << " " << i;
    }
    
    for (int i = 1; i < r; i++) {
        cout << " " << i;
    }
    cout << endl;
    
    for (int y = 0; y < r; y++) {
        cout << y;
        for (int x = 0; x < c; x++) {
            b[x][y] = a;
            cout << b[x][y] << " "; 
        }
        cout << endl;
    }
    
    
}

void printBoard2(char**b, int r, int c) {
    
    for (int i = 0; i < 1; i++) {
        cout << " " << i;
    }
    
    for (int i = 1; i < r; i++) {
        cout << " " << i;
    }
    cout << endl;
    
    for (int y = 0; y < r; y++) {
        cout << y;
        for (int x = 0; x < c; x++) {
            cout << b[x][y] << " ";
        }
        cout << endl;
    }
    
    
}
