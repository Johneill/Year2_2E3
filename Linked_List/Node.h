//
//  Node.h
//  
//
//  Created by David Neill on 22/11/2017.
//
//

#ifndef Node_h
#define Node_h
#include <iostream>
#include <iomanip>
#include <string>
#endif /* Node_h */
using namespace std;

class StudentNode{
private:
    int ID;
    string firstName;
    double finalGrade;
    StudentNode* nextP;
    StudentNode* currP;
    
    
public:
    StudentNode(int num, string name, double grade);
    int getID();
    string getName();
    double getGrade();
    StudentNode* getNext();
    void setNext(StudentNode* _next);
    StudentNode* findByName(string name);
    StudentNode* findByID(int num);

    
    
  };
