//
//  check.h
//  
//
//  Created by David Neill on 30/10/2017.
//
//

#ifndef check_h
#define check_h
#include <iostream>
#include <cmath>

using namespace std;


#endif /* check_h */

class check{
    
    private:
    
    public:
         int check1 (int c, int d, char**b, char w, char B, int x){
            
            x=0;
             
             //cout << x << "        q"<< endl;
            
             if (c-1<0){
                 
                 //cout << x << "        q"<< endl;

                 
                 if (b[c][d+1]== B || b[c][d+1]== w){
                     x++;
                 }
                // cout << x << "        q"<< endl;
                 if (b[c+1][d+1]== B || b[c+1][d+1]== w){
                     x++;
                 }
                 if (b[c+1][d]== B || b[c+1][d]== w){
                     x++;
                 }
                 if (b[c+1][d-1]== B || b[c+1][d-1]== w){
                     x++;
                 }
                 if (b[c][d-1]== B || b[c][d-1]== w){
                     x++;
                 }
                 
             }
             
            if (c-1>=0){
            if (b[c-1][d+1]== B){
                x++;
            }
                
            if (b[c][d+1]==B){
                 x++;
            }
            
            if (b[c+1][d+1]== B){
                    x++;
            }
                
            if (b[c-1][d]==B){
                    x++;
            }
            if (b[c+1][d]== B){
                x++;
            }
            if (b[c-1][d-1]==B){
                x++;
            }
            if (b[c][d-1]== B){
                x++;
            }
            if (b[c+1][d-1]==B){
                x++;
            }
            if (b[c-1][d+1]== w){
                x++;
            }
            
            if (b[c][d+1]==w){
                x++;
            }
            
            if (b[c+1][d+1]== w){
                x++;
                
            }
            if (b[c-1][d]==w ){
                x++;
                
            }
            if (b[c+1][d]== w){
                x++;
                
            }
            if (b[c-1][d-1]==w){
                x++;
                
            }
            if (b[c][d-1]== w ){
                
                x++;
            }
            if (b[c+1][d-1]==w ){
                x++;
                
            }
            }
             if (b[c][d]== w ||  b[c][d]== B){
                 x=0;
             }
             //cout << x << "        q"<< endl;
            return (x);
        }


};
