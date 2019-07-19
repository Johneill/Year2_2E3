//
//  array_board.cpp
//  
//
//  Created by David Neill on 10/10/2017.
//
//

#include "array_board.hpp"
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main(){
    int x,y;
    char array [5][5];
    char ___ ,L___,|;

    
    array[1][0] == ___;
    array[3][0] == ___;
    array[0][1] == L___;
    array[0][3] == L___;
    array[3][1] == L___;
    array[3][3] == L___;
    
    
    for (y=0;y<5; y++){
        for(x=0; x<5; x++){
            cout << array[x][y]
        }
    }
    return 0;
}

