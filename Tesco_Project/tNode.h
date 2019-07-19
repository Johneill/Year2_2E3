//
//  tNode.h
//  
//
//  Created by David Neill on 15/01/2018.
//
//

#ifndef tNode_h
#define tNode_h
#endif /* tNode_h */
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class tescoNode{
private:
    string Name;
    string BBD1;
    double Price;
    int Quantity;
    string Firstname;
    string Secondname;
    string Address;
    double Points;
    double ID;
    tescoNode* nextP;
    tescoNode* currP;
    
    
public:
    tescoNode(string name, string BBD, double price, int quantity);
    tescoNode(double id,string firstname, string secondname, string address, double points);
    string getName();
    string getBBD1();
    double getPrice();
    int getQuantity();
    string getFirstname();
    string getSecondname();
    string getAddress();
    double getPoints();
    double getID();
    tescoNode* getNext();
    void setNext(tescoNode* _next);
    tescoNode* findByName(string name);
    tescoNode* findByID(int num);


    
    
};
