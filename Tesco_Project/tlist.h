//
//  tlist.h
//  
//
//  Created by David Neill on 15/01/2018.
//
//

#ifndef tlist_h
#define tlist_h
#pragma once


#endif /* tlist_h */
#include <iostream>
#include <iomanip>
#include <string>

//using namespace std;

class tescoList {
private:
    tescoNode* headP;
    tescoNode* tailP;
    int length;
public:
    tescoList();
    ~tescoList();
    bool removeNode(string name);
    void printAlltesco();
    tescoNode* findByName(string firstname,string secondname, double points);
    tescoNode* findByName1(string name);
    tescoNode* sort(int n);
    tescoNode* removebyname(string firstname);
    tescoNode* removebyidandname(int num, string name);
    tescoNode* findByID(int num);
    void addtesco(string name, string BBD, double price, int quantity);
    void addfreshfruit(string name, string BBD, double price, int quantity);
    void recipttesco(string name, string BBD, double price, int quantity);
    void addclubcard(double id,string firstname, string secondname, string address, double points);
    int getLength();
};

