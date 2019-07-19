//
//  reversi.cpp
//  
//
//  Created by David Neill on 29/10/2017.
//
//
#include "check.h"
#include "reversi.hpp"
#include <iostream>
#include "printboard.h"
//#include "player1.h"
//#include "player2.h"


using namespace std;
void printBoard(char**b);
void printBoard2(char**b);
void checkboard(char**b, int c, int d);
void turning(char**b, int c, int d);
void turning1(char**b, int c, int d);
void winner (char**b, int sequence);

int player;
int c, d;
const char a = '-';
const int player1 = 1;
const int player2 = 2;
const char w = 'W';
const char B = 'B';
bool gameover=false;

int main() {
    int sequence = 1;
    int x;
    int u;
    int z;
    
    char**board; // repeat this to delete other way
    board = new char*[9];
    for (int i = 0;i<9;i++)
        board[i] = new char[9];
    cout << endl;
    cout << "Welcome to Reversi... Let's Play!!" << endl;
    

    //printBoard(board);
    
    printboard print;
    print.printBoard(board);
    
    while (!gameover) {
        
        player = player1;
        if (sequence % 2 == 0) {
            player = player2;
        }
        else player = player1;
    
        
    cout  << "Please enter the co-ordinates player "<< player <<" where you want your piece to go"<< endl;
    cin >> c >> d;
        cout << endl;
        
        z=c;
        
        check one; // defining class
        if (one.check1(c,d,board,w,B,u)>=1){ // using the function in the class to check if spaces are free
            c=z;
        checkboard(board,c, d);
        turning(board, c, d);
            
        }
        else{ cout << endl << "You are not able to go here, select other co-ordinates" << endl;
            sequence--;
        cout << endl;
        }
        
        
        //printBoard2(board);
        print.printBoard1(board);
        sequence++;
        winner(board, sequence);
        }
    
    
    cin.get();
    cin.get();
    
    return 0;
}



void checkboard(char**b, int c, int d){
    if (b[c][d]== a ){
        if (player == player1){
            b[c][d]=B;
        }
        if (player == player2){
            b[c][d]=w;
        }

        
    }
   
}

void turning(char**b, int c, int d){
    
    if (c-1<0){
       
        //cout<< "to the right and works"<< endl;
    int x2=0;
    int y=d;
    if (player==player1){
        for (int i = c; i<=7; i++){
            if (b[i][y]==w){
                x2++;
                
            }
            
        }
        if (b[c+(x2+1)][d]==a){
            x2=0;
        }
        if (b[c+(x2+1)][d]==B){
            for (int i=c; i<=(c+x2); i++){
                b[i][y]=B;
                
            }
        }
        x2=0;
    }
    if (player==player2){
        for (int i = c; i<=7; i++){
            if (b[i][y]==B){
                x2++;
            }
        }
        if (b[c+(x2+1)][d]==a){
            x2=0;
        }
        
        if (b[c+(x2+1)][d]==w){
            for (int i=c; i<=(c+x2); i++){
                b[i][y]=w;
            }
        }
        x2=0;
    }
    
    // up and works
        //cout<< "to the right and works"<< endl;
    int x4=0;
    y=c;
    if(player==player1){
        
        
        for (int i=d; i>=0; i--){
            if (b[y][i-1]==w){
                x4++;
            }
        }
        if (b[c][d-(x4+1)]==a){
            x4=0;
        }
        
        if (b[c][d-(x4+1)]==B){
            for (int i=d; i>=(d-x4); i--){
                b[y][i]=B;
            }
            x4=0;
        }
    }
    if(player==player2){
        
        
        for (int i=d; i>=0; i--){
            if (b[y][i-1]==B){
                x4++;
            }
        }
        if (b[c][d-(x4+1)]==a){
            x4=0;
        }
        cout << x4 << endl;
        
        if (b[c][d-(x4+1)]==w){
            for (int i=d; i>=(d-x4); i--){
                b[y][i]=w;
            }
            x4=0;
        }
    }
    
    //down and works
        //cout<< "to the right and works"<< endl;
    int x5=0;
    y=c;
    if (player==player1){
        for (int i=d; i<=7; i++){
            if (b[y][i]==w){
                x5++;
            }
        }
        if (b[c][d+(x5+1)]==a){
            x5=0;
            //cout << x1 << " dhdw22"<< endl;
        }
        if (b[c][d+(x5+1)]==B){
            for (int i=d; i<=(d+x5); i++){
                b[y][i]=B;
            }
        }
        x5=0;
    }
    if (player==player2){
        for (int i=d; i<=7; i++){
            if (b[y][i]==B){
                x5++;
            }
        }
        if (b[c][d+(x5+1)]==a){
            x5=0;
            //cout << x1 << " dhdw22"<< endl;
        }
        if (b[c][d+(x5+1)]==w){
            for (int i=d; i<=(d+x5); i++){
                b[y][i]=w;
            }
        }
        x5=0;
    }
    
    //upright and works
    int x6=0;
    y=d;
    if (player==player1){
        for (int i=c; i<=7; i++){
            if (b[i+1][y-1]==w){
                x6++;
                //cout << x6 << " jhjhjhj"<< endl;
                
            }
            if (b[c+(x6+1)][d-(x6+1)]==a){
                x6=0;
            }
            y--;
        }
        
        
        
        y=d;
        
        if (b[c+(x6+1)][d-(x6+1)]==B){
            for (int i=1; i<(x6+1) ; i++){
                b[c+i][y-1]= B;
                y--;
            }
            x6=0;
        }
        
    }
    if (player==player2){
        for (int i=c; i<=7; i++){
            if (b[i+1][y-1]==B){
                x6++;
                //cout << x6 << "jhjhjhj"<< endl;
                
            }
            if (b[c+(x6+1)][d-(x6+1)]==a){
                x6=0;
            }
            y--;
        }
        
        
        y=d;
        
        if (b[c+(x6+1)][d-(x6+1)]==w){
            for (int i=1; i<x6+1 ; i++){
                b[c+i][y-1]= w;
                y--;
            }
            x6=0;
        }
    }
    
    //downwardright and works
    int x1=0;
    if (player==player1){
        
        for (int i=c; i<=7; i++){
            if (b[i+1][y+1]==w){
                x1++;
                
            }
            if (b[c+(x1+1)][d+(x1+1)]==a){
                x1=0;
            }
            y++;
        }
        
        
        y=d;
        
        if (b[c+(x1+1)][d+(x1+1)]==B){
            for (int i=1; i<x1+1 ; i++){
                b[c+i][y+1]= B;
                y++;
            }
            x1=0;
        }
    }
    if (player==player2){
        for (int i=c; i<=7; i++){
            if (b[i+1][y+1]==B){
                x1++;
                
            }
            if (b[c+(x1+1)][d+(x1+1)]==a){
                x1=0;
            }
            y++;
        }
        
        
        y=d;
        
        if (b[c+(x1+1)][d+(x1+1)]==w){
            for (int i=1; i<x1+1 ; i++){
                b[c+i][y+1]= w;
                y++;
            }
            x1=0;
            
        }
    }
    
    }
    
    if (c-1>=0){
    
    
    //downwardleft and works
    int y=d;
    int x1=0;
    if(player==player1){
        
    for (int i=c; i>=1; i--){
        if (player==player1){
            if (b[i-1][y+1]==w){
                x1++;
                
            }
            if (b[c-(x1+1)][d+(x1+1)]==a){
                x1=0;
            }
            y++;
        }
    }
    
    y=d;
    
        if (b[c-(x1+1)][d+(x1+1)]==B){
            for (int i=1; i<x1+1 ; i++){
                b[c-i][y+1]= B;
                y++;
            }
            x1=0;
        }
    }
    if(player==player2){
        for (int i=c; i>=1; i--){
            if (player==player1){
                if (b[i-1][y+1]==B){
                    x1++;
                    
                }
                if (b[c-(x1+1)][d+(x1+1)]==a){
                    x1=0;
                }
                y++;
            }
        }
        
        y=d;
        
        if (b[c-(x1+1)][d+(x1+1)]==w){
            for (int i=1; i<x1+1 ; i++){
                b[c-i][y+1]= w;
                y++;
            }
            x1=0;
        }
    }

    // to the right and works
    int x2=0;
    y=d;
    if (player==player1){
    for (int i = c; i<=7; i++){
        if (b[i][y]==w){
            x2++;
            
        }
        
    }
        if (b[c+(x2+1)][d]==a){
            x2=0;
        }
        if (b[c+(x2+1)][d]==B){
            for (int i=c; i<=(c+x2); i++){
            b[i][y]=B;

            }
        }
    x2=0;
    }
    if (player==player2){
        for (int i = c; i<=7; i++){
            if (b[i][y]==B){
                x2++;
                }
        }
        if (b[c+(x2+1)][d]==a){
            x2=0;
        }
        
        if (b[c+(x2+1)][d]==w){
            for (int i=c; i<=(c+x2); i++){
                b[i][y]=w;
            }
        }
        x2=0;
    }
   
    //to the left and works
    int x3=0;
    y=d;
    if (player==player1){
        
    for (int i = c; i>=1; i--){
        if (b[i-1][y]==w){
            x3++;
        }
    }
        if (b[c-(x3+1)][d]==a){
            x3=0;
        }
    
        if (b[c-(x3+1)][d]==B){
        for (int i=c; i>=(c-x3); i--){
            b[i][y]=B;
            }
        }
    x3=0;
    }
    if (player==player2){
        
            for (int i = c; i>=1; i--){
            if (b[i-1][y]==B){
                
                x3++;
                //cout << x3 << " deded"<< endl;
            }
        }
            if (b[c-(x3+1)][d]==a){
                x3=0;
            }
            
            if (b[c-(x3+1)][d]==w){
                
                for (int i=c; i>=(c-x3); i--){
                    b[i][y]=w;
                }
            }
            x3=0;

    
    }
    
    // up and works
    int x4=0;
    y=c;
    if(player==player1){
        
        
    for (int i=d; i>=0; i--){
        if (b[y][i-1]==w){
            x4++;
        }
    }
        if (b[c][d-(x4+1)]==a){
            x4=0;
        }
    
    if (b[c][d-(x4+1)]==B){
            for (int i=d; i>=(d-x4); i--){
                b[y][i]=B;
        }
    x4=0;
    }
    }
    if(player==player2){
        
        
        for (int i=d; i>=0; i--){
            if (b[y][i-1]==B){
                x4++;
            }
        }
        if (b[c][d-(x4+1)]==a){
            x4=0;
        }
        cout << x4 << endl;
        
        if (b[c][d-(x4+1)]==w){
            for (int i=d; i>=(d-x4); i--){
                b[y][i]=w;
            }
            x4=0;
        }
    }

    //down and works
    int x5=0;
    y=c;
    if (player==player1){
    for (int i=d; i<=7; i++){
        if (b[y][i]==w){
            x5++;
        }
    }
        if (b[c][d+(x5+1)]==a){
            x5=0;
            //cout << x1 << " dhdw22"<< endl;
        }
        if (b[c][d+(x5+1)]==B){
            for (int i=d; i<=(d+x5); i++){
                b[y][i]=B;
            }
    }
    x5=0;
    }
    if (player==player2){
        for (int i=d; i<=7; i++){
            if (b[y][i]==B){
                x5++;
            }
        }
        if (b[c][d+(x5+1)]==a){
            x5=0;
            //cout << x1 << " dhdw22"<< endl;
        }
        if (b[c][d+(x5+1)]==w){
            for (int i=d; i<=(d+x5); i++){
                b[y][i]=w;
            }
        }
        x5=0;
    }
    
    //upright and works
    int x6=0;
    y=d;
    if (player==player1){
        
        for (int i=c; i<=7; i++){
                if (b[i+1][y-1]==w){
                    x6++;
                    cout << x6 << " jhjhjhj"<< endl;
                    
                }
                if (b[c+(x6+1)][d-(x6+1)]==a){
                    x6=0;
                }
                y--;
            }
        
    
        
        y=d;
        cout << x6 << " jhjhjhj"<< endl;2 4
        
        if (b[c+(x6+1)][d-(x6+1)]==B){
            for (int i=1; i<(x6+1) ; i++){
                b[c+i][y-1]= B;
                y--;
            }
            x6=0;
        }
    
    }
    if (player==player2){
        for (int i=c; i<=7; i++){
            if (b[i+1][y-1]==B){
                x6++;
                //cout << x6 << "jhjhjhj"<< endl;
                
            }
            if (b[c+(x6+1)][d-(x6+1)]==a){
                x6=0;
            }
            y--;
        }
    
    
    y=d;
    
    if (b[c+(x6+1)][d-(x6+1)]==w){
        for (int i=1; i<x6+1 ; i++){
            b[c+i][y-1]= w;
            y--;
        }
        x6=0;
    }
    }

    //downwardright and works
    x1=0;
    if (player==player1){
        
        for (int i=c; i<=7; i++){
                if (b[i+1][y+1]==w){
                    x1++;
                    
                }
                if (b[c+(x1+1)][d+(x1+1)]==a){
                    x1=0;
                }
                y++;
            }
        
        
        y=d;
        
        if (b[c+(x1+1)][d+(x1+1)]==B){
            for (int i=1; i<x1+1 ; i++){
                b[c+i][y+1]= B;
                y++;
            }
            x1=0;
        }
    }
    if (player==player2){
        for (int i=c; i<=7; i++){
            if (b[i+1][y+1]==B){
                x1++;
                
            }
            if (b[c+(x1+1)][d+(x1+1)]==a){
                x1=0;
            }
            y++;
        }
    
    
    y=d;
    
    if (b[c+(x1+1)][d+(x1+1)]==w){
        for (int i=1; i<x1+1 ; i++){
            b[c+i][y+1]= w;
            y++;
        }
        x1=0;
        
        }
    }
    
    //upward left and works
    x1=0;
    if (player==player1){
        for (int i=c; i>=1; i--){
            if (b[i-1][y-1]==w){
                x1++;
                
            }
            if (b[c-(x1+1)][d-(x1+1)]==a){
                x1=0;
            }
            y--;
        }
        
        
        y=d;
        
        if (b[c-(x1+1)][d-(x1+1)]==B){
            for (int i=1; i<x1+1 ; i++){
                b[c-i][y-1]= B;
                y--;
            }
            x1=0;
        }
    }
    if (player==player2){
        for (int i=c; i>=1; i--){
            if (b[i-1][y-1]==B){
                x1++;
                
            }
            if (b[c-(x1+1)][d-(x1+1)]==a){
                x1=0;
            }
            y--;
        }
        
        
        y=d;
        
        if (b[c-(x1+1)][d-(x1+1)]==w){
            for (int i=1; i<x1+1 ; i++){
                b[c-i][y-1]= w;
                y--;
            }
            x1=0;
        }
        
    }
}
}

void winner (char**b, int sequence){
    
    int p=0;
    int l=0;
    if (sequence==61){
        for(int i=0; i<=7; i++){
            for(int y=0; y<=7; y++){
                if (b[i][y]==B){
                    p++;
                }
                if (b[i][y]==w){
                    l++;
                }
                    
            }
        }
        
        if (p>l){
            cout << "Player 1 wins" << endl;
            cout << "Black counters = "<< p << endl;
            cout << "White counters = "<< l << endl;
        }
        else {
            cout << "Player 2 wins" << endl;
             cout << "White counters = "<< l << endl;
            cout << "Black counters = "<< p << endl;
            
        }
        
        gameover=true;
        
    }
}





