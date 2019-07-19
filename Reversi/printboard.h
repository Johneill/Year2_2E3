//
//  printboard.h
//  
//
//  Created by David Neill on 15/11/2017.
//
//

#ifndef printboard_h
#define printboard_h

#include <iostream>
#include <cmath>

using namespace std;

#endif /* printboard_h */

class printboard {
private:
    const char a = '-';
    const char w = 'W';
    const char B = 'B';
    
public:
    void printBoard(char**b){
        for (int i=1; i<=7; i++){
            cout << "***";
        }
        cout << "**";
        
        cout << endl;
        cout << "*";
        
        for (int i = 0; i < 1; i++) {
            cout << "    " << i;
        }
        
        for (int i = 1; i < 8; i++) {
            cout << " " << i;
        }
        cout << "  *";
        cout << endl;
        cout << "*";
        
        for (int y = 0; y < 8; y++) {
            
            cout <<"  " << y << " ";
            
            for (int x = 0; x < 8; x++) {
                b[x][y] = a;
                b[3][3] = B;
                b[3][4] = w;
                b[4][3] = w;
                b[4][4] = B;
                cout << b[x][y] << " ";
            }
            cout << " *";
            cout << endl;
            cout << "*";
        }
        for (int i=1; i<=7; i++){
            cout << "***";
        }
        cout << "*";
        cout << endl;
        cout << endl;
    }
    void printBoard1(char**b){
        for (int i=1; i<=7; i++){
            cout << "***";
        }
        cout << "**";
        
        cout << endl;
        cout << "*";
        
        for (int i = 0; i < 1; i++) {
            cout << "    " << i;
        }
        
        for (int i = 1; i < 8; i++) {
            cout << " " << i;
        }
        cout << "  *";
        cout << endl;
        cout << "*";
        
        for (int y = 0; y < 8; y++) {
            
            cout <<"  " << y << " ";
            for (int x = 0; x < 8; x++) {
                cout << b[x][y] << " ";
            }
            cout << " *";
            cout << endl;
            cout << "*";
        }
        for (int i=1; i<=7; i++){
            cout << "***";
        }
        cout << "*";
        cout << endl;
        cout << endl;
    }

    

    
};
