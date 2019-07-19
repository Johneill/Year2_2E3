//
//  list.h
//  
//
//  Created by David Neill on 22/11/2017.
//

#pragma once
#include <iostream>
#include <string>


using namespace std;


class StudentList {
private:
    StudentNode* headP;
    StudentNode* tailP;
    int length;
public:
    StudentList();
    ~StudentList();
    bool removeNode(int num);
    void printAllStudents();
    StudentNode* findByName(string name);
    StudentNode* sort(int n);
    StudentNode* removebyname(string name);
    void insertAfter(string name, string name1,int &num, double grade,StudentNode* findNode);
    StudentNode* removebyidandname(int num, string name);
    StudentNode* findByID(int num);
    void addStudent(int &num, string name, double grade);
    void addStudent1(int &num, string name, double grade);
    int getLength();
};


