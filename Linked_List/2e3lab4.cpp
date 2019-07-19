//
//  2e3lab4.cpp
//  
//
//  Created by David Neill on 22/11/2017.
//

#include <stdio.h>
#include <string>
#include "Node.h"
#include "List.h"

StudentList::StudentList(){
    headP = NULL;
    tailP = NULL;
    length = 0;
}

StudentList::~StudentList(){
    StudentNode *currP;
    while (headP!=NULL){
        currP=headP;
        headP=headP->getNext();
        delete currP;
    }
}


void StudentList::printAllStudents() {
    StudentNode* currNode;
    currNode = headP;
    while (currNode != NULL) {
        cout << currNode->getID() << " ";
        cout << currNode->getName() << " ";
        cout << currNode->getGrade() << " ";
        currNode = currNode->getNext();
        cout << endl;
    }
    cout << endl;
}

StudentNode::StudentNode(int num, string name, double grade){
    ID = num;
    firstName = name;
    finalGrade = grade;
    nextP = NULL;
}

void StudentList::addStudent(int &num, string name, double grade) {
    StudentNode* newNode = new StudentNode(num, name, grade);
    if (tailP == NULL)
        headP = tailP = newNode;
    else {
        tailP->setNext(newNode);
        tailP = newNode;
    }
    num++;
}

void StudentList::addStudent1(int &num, string name, double grade) {
    StudentNode* newNode = new StudentNode(num, name, grade);
    if (tailP == NULL)
        headP = tailP = newNode;
    else {
        tailP->setNext(newNode);
        tailP = newNode;
    }

}


int StudentNode::getID() {
    return ID;
}

string StudentNode::getName() {
    return firstName;
}

double StudentNode::getGrade() {
    return finalGrade;
}

StudentNode* StudentNode::getNext() {
    return nextP;
}

void StudentNode::setNext(StudentNode* _next) {
    nextP = _next;
}

StudentNode* StudentList::findByName(string name){
    StudentNode* currNode;
    currNode = headP;
    string nodeName;
    while (currNode != NULL) {
        nodeName = currNode->getName();
        if(nodeName == name){
            return currNode;
        }
        currNode = currNode->getNext();
        cout << endl;
    }
    return NULL;
}

StudentNode* StudentList::removebyname(string name){
    StudentNode* currNode;
    StudentNode* tempNode;
    StudentNode* allNode;
    currNode = headP;
    allNode = headP;
    tempNode= headP->getNext();
    string nodeName, nodeName1;
    nodeName = currNode->getName();
    if(nodeName==name){
        headP=currNode->getNext();
        delete currNode;
    }
    
    while (tempNode != NULL) {
        nodeName1 = tempNode->getName();
        if(nodeName1 == name){
            currNode = currNode->getNext()->getNext();
            delete tempNode;
        }
        currNode = currNode->getNext();
        tempNode = tempNode->getNext();
        cout << endl;
    }
    return NULL;
}


bool StudentList::removeNode(int num) {
    StudentNode* curr = headP;
    StudentNode* prev = headP;
    while (curr != 0) {
        if (curr->getID() == num) {
        
            if (curr == headP) {
       
                headP = curr->getNext();
            }
            else {

                prev->setNext(curr->getNext());
                if (curr == tailP) {
         
                    tailP = prev;
                }
            }
            delete curr;
            return true;         }
        
        prev = curr;
        curr->setNext(curr->getNext());
        curr=curr->getNext();
    }
    
    return false;
}

StudentNode* StudentList::removebyidandname(int num, string name){
    StudentNode* currNode;
    StudentNode* tempNode;
    currNode = headP;
    tempNode= headP->getNext();
    int nodeID, nodeID1;
    string nodeName, nodeName1;
    nodeID = currNode->getID();
    nodeName = currNode->getName();
    
    if(nodeID==num && nodeName==name){
        headP=headP->getNext();
        delete currNode;
    }
    while (tempNode != NULL) {
        nodeID1 = tempNode->getID();
        nodeName1 =tempNode->getName();
        if(nodeID1 == num && nodeName1==name){
            currNode = currNode->getNext()->getNext();
            delete tempNode;
        }
        currNode = currNode->getNext();
        tempNode = tempNode->getNext();
        cout << endl;
    }
    return NULL;
}


void StudentList::insertAfter(string name, string name1, int &num, double grade, StudentNode* findNode){
    StudentNode* prevNode;
    StudentNode* prevNext;
    StudentList l1;
    
    StudentNode* newNode = new StudentNode(num, name, grade);
    prevNode=findNode;
    prevNext = prevNode->getNext();
    //cout << "jdbcjcbwj "<<endl;
    prevNode->setNext(newNode);
    //cout << "jdbcjcbwj "<<endl;
    newNode->setNext(prevNext);
    //cout << "jdbcjcbwj "<<endl;
}



StudentNode* StudentList::findByID(int num){
    StudentNode* currNode;
    currNode = headP;
    int nodeID;
    while (currNode != NULL) {
        nodeID = currNode->getID();
        if(nodeID == num){
            return currNode;
        }
        currNode = currNode->getNext();
        cout << endl;
    }
    return NULL;
}

StudentNode* getPrevious(StudentNode* headP, StudentNode* temp){
    StudentNode* curr;
    StudentNode* curr1;
    
    curr=headP;
    curr1=headP;
    curr=curr->getNext();
    while (curr!=temp){
        curr=curr->getNext();
        curr1=curr1->getNext();
        
        
    }
    
    
    
    
    
    return curr1;
    
    
}





int main(){
    StudentList l1;
    int num, findNum;
    string name, findName, response, answer, removebyname, insertname, insertname1;
    double grade, removebyid;
    int numStudents =1;
    StudentNode* findNode;
    int n;
    int i=1;
    int q;
    cout << endl;
    cout << "How many students do you want to enter?" << endl;
    cin >> n;
    cout << endl;
    
    cout << "Do you want to enter ID (0 for no, 1 or yes)" << endl;
    cin >> q;
    
    while (i<=n){
        if (q==1){
        cout << "Enter ID, name, and grade: ";
        cin >> num >> name >> grade;
        l1.addStudent(num, name, grade); //add to list
            i++;
    
        }
        
        if (q==0){
        
            cout << "Enter name, and grade: ";
            cin >> name >> grade;
            l1.addStudent1(i,name, grade); //add to list
            i++;
        }
            
        }
        
    
    l1.printAllStudents();
    cout << endl;
    answer="yes";
    while (answer=="yes"){
    cout << "Would you like to search by ID or by name?" << endl;
    cin >> response;
    if (response == "ID" || response == "id"){
        cout << "Enter ID: ";
        cin >> findNum;
        findNode = l1.findByID(findNum);
        if (findNode==NULL){
            cout << "this is invalid ID try again" << endl;
        }
        else
            cout << "Student info: " << findNode->getName() << " " << findNode->getGrade() << endl;
    }
    else {
        cout << "Enter Name: ";
        cin >> findName;
        findNode = l1.findByName(findName);
        if (findNode==NULL){
            cout << "this is invalid ID try again" << endl;
        }
        else
        cout << "Student info: " << findNode->getID() << " " << findNode->getGrade() << endl;
    }
    
    cout << "Would you like to searh for another student" << endl;
    cin >> answer;
    cout << endl;
    }
   
    cout << "Do you want to delete a person"<< endl;
    cin >> answer;
    cout << endl;
    
    if (answer=="yes" || answer=="Yes"){
        cout << "Do you want to delete by name or ID or both"<< endl;
        cin >> answer;
        cout << endl;
    
        if (answer=="name" || answer=="Name"){
            cout << "Select a name you want to delete" << endl;
            cin>> removebyname;
            findNode= l1.removebyname(removebyname);
        }
    
        if (answer=="ID" || answer=="id"){
        cout << "Select a ID you want to delete" << endl;
        cin>> removebyid;
         l1.removeNode(removebyid);
        }
        
        if (answer=="both"|| answer=="Both"){
            cout << "Enter name and ID" << endl;
            cin >> name >> num;
            cout << endl;
          l1.removeNode(num);
            
        }
    }
    
    cout << "Do you want to insert a person?"<< endl;
    cin >> answer;
    cout << endl;
    
    if (answer=="yes" || answer=="Yes"){
        cout << " Insert the name, ID and Grade you want to insert:"<< endl;
        cin >> insertname>> num>> grade;
        cout<< endl;
        
        cout << " Insert the name you want to be after the name you inputted:"<< endl;
        cin >> insertname1;
        cout<< endl;
        
        findNode= l1.findByName(insertname1);
        
        l1.insertAfter(insertname,insertname1, num, grade,findNode);
     
        
        
    }
    
   /* cout << "Do you want to sort in ascending order or descending order"<< endl;
    cin >> answer;
    cout << endl;
    
    if (answer=="ascending"){
        findNode=l1.sort(n);
        
    }
    
    if (answer=="descending"){
        
    }*/

    
    
    
    l1.printAllStudents();
    //l1.~StudentList();
    //l1.printAllStudents();
    
    return 0;
}









