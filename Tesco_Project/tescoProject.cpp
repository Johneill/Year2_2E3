//
//  tescoProject.cpp
//  
//
//  Created by David Neill on 15/01/2018.
//
//

#include "tescoProject.hpp"
#include <stdio.h>
#include <string>
#include <fstream>
#include "tNode.h"
#include "tList.h"



using namespace std;

tescoList::tescoList(){
    headP = NULL;
    tailP = NULL;
    length = 0;
}

tescoList::~tescoList(){
    tescoNode *currP;
    while (headP!=NULL){
        currP=headP;
        headP=headP->getNext();
        delete currP;
    }
}

void tescoList::printAlltesco() {
    tescoNode* currNode;
    currNode = headP;
    while (currNode != NULL) {
        cout << currNode->getName() << " ";
        cout << currNode->getBBD1() << " ";
        cout << currNode->getPrice() << " ";
        cout << currNode->getQuantity() << " ";
        currNode = currNode->getNext();
        cout << endl;
    }
    cout << endl;
}

tescoNode::tescoNode( string name, string BBD, double price, int quantity){
    Name = name;
    BBD1 = BBD;
    Price = price;
    Quantity=quantity;
    nextP = NULL;
}
tescoNode::tescoNode(double id,string firstname, string secondname, string address, double points){
    ID=id;
    Firstname = firstname;
    Secondname = secondname;
    Address = address;
    Points=points;
    nextP = NULL;
}


void tescoList::addtesco(string name, string BBD, double price, int quantity) {
    tescoNode* newNode = new tescoNode(name ,BBD ,price , quantity);
    if (tailP == NULL)
        headP = tailP = newNode;
    else {
        tailP->setNext(newNode);
        tailP = newNode;
    }
    //num++;
}

void tescoList::addclubcard(double id, string firstname, string secondname, string address, double points) {
    tescoNode* newNode = new tescoNode(id,firstname,secondname,address,points);
    if (tailP == NULL)
        headP = tailP = newNode;
    else {
        tailP->setNext(newNode);
        tailP = newNode;
    }
    //num++;
}


void tescoList::recipttesco(string name, string BBD, double price, int quantity) {
    tescoNode* newNode = new tescoNode(name ,BBD ,price , quantity);
    if (tailP == NULL)
        headP = tailP = newNode;
    else {
        tailP->setNext(newNode);
        tailP = newNode;
    }
    
}

void tescoList::addfreshfruit(string name, string BBD, double price, int quantity) {
    tescoNode* newNode = new tescoNode(name ,BBD ,price , quantity);
    if (tailP == NULL)
        headP = tailP = newNode;
    else {
        tailP->setNext(newNode);
        tailP = newNode;
    }
    
}

double tescoNode::getID() {
    return ID;
}

string tescoNode::getName() {
    return Name;
}

string tescoNode::getBBD1() {
    return BBD1;
}

double tescoNode::getPrice() {
    return Price;
}

int tescoNode::getQuantity() {
    return Quantity;
}

string tescoNode::getFirstname() {
    return Firstname;
}

string tescoNode::getSecondname() {
    return Secondname;
}

string tescoNode::getAddress() {
    return Address;
}

double tescoNode::getPoints() {
    return Points;
}

tescoNode* tescoNode::getNext() {
    return nextP;
}

void tescoNode::setNext(tescoNode* _next) {
    nextP = _next;
}

tescoNode* tescoList::findByName(string firstname, string secondname,double points){
    tescoNode* currNode;
    tescoNode* findNode;
    currNode = headP;
    string nodeName1;
    string nodeName2;
    while (currNode != NULL) {
        nodeName1 = currNode->getFirstname();
        nodeName2 = currNode->getSecondname();
        if(nodeName1 == firstname && nodeName2==secondname){
            return currNode;
        }
        currNode = currNode->getNext();
        cout << endl;
    }
    return NULL;
}

tescoNode* tescoList::findByName1(string name){
    tescoNode* currNode;
    currNode = headP;
    string nodeName1;
    while (currNode != NULL) {
        nodeName1 = currNode->getName();
        if(nodeName1 == name){
            return currNode;
        }
        currNode = currNode->getNext();
        cout << endl;
    }
    return NULL;
}

tescoNode* tescoList::removebyname(string name){
    tescoNode* currNode;
    tescoNode* tempNode;
    tescoNode* allNode;
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


bool tescoList::removeNode(string name) {
    tescoNode* curr = headP;
    tescoNode* prev = headP;
    while (curr != 0) {
        if (curr->getName() == name ) {
            
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
/*
tescoNode* tescoList::removebyidandname(int num, string name){
    tescoNode* currNode;
    tescoNode* tempNode;
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
}*/


/*tescoNode* tescoList::findByID(int num){
    tescoNode* currNode;
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

tescoNode* getPrevious(tescoNode* headP, tescoNode* temp){
    tescoNode* curr;
    tescoNode* curr1;
    
    curr=headP;
    curr1=headP;
    curr=curr->getNext();
    while (curr!=temp){
        curr=curr->getNext();
        curr1=curr1->getNext();
        
        
    }
    
    
    
    
    
    return curr1;
    
    
}*/


int main(){
    
    string name;
    string BBD;
    int quantity;
    double price, points,id,costoff,money;
    double cost=0;
    string ordered, clubcardanswer, firstname, secondname, joining, address, pointsanswer,slist,deleted;
    string answer,food,biganswer;
    tescoList Fresh_Food;
    tescoList Bakery;
    tescoList Frozen_Food;
    tescoList Food_Cupboard;
    tescoList Drinks;
    tescoList Clubcard;
    tescoNode* findNode;
    tescoList l1;
    
    fstream clubcard;
    clubcard.open("clubcard.txt", ios::in | ios::out);
    ifstream recipt;
    recipt.open("recpit.txt");
    ifstream fresh_food;
    fresh_food.open("Fresh_Food.txt");
    ifstream bakery;
    bakery.open("Bakery.txt");
    ifstream frozen_food;
    frozen_food.open("Frozen_Food.txt");
    ifstream food_cupboard;
    food_cupboard.open("Food_Cupboard.txt");
    ifstream drinks;
    drinks.open("Drinks.txt");
    

    for (int count = 0; count < 5; count++){
        fresh_food >> name;
        fresh_food >> BBD;
        fresh_food >> quantity;
        fresh_food >> price;
        Fresh_Food.addfreshfruit(name, BBD, price,quantity);
        
        bakery >> name;
        bakery >> BBD;
        bakery >> quantity;
        bakery >> price;
        Bakery.addfreshfruit(name, BBD, price,quantity);
        
        frozen_food >> name;
        frozen_food >> BBD;
        frozen_food >> quantity;
        frozen_food >> price;
        Frozen_Food.addfreshfruit(name, BBD, price,quantity);

        
        food_cupboard >> name;
        food_cupboard >> BBD;
        food_cupboard >> quantity;
        food_cupboard >> price;
        Food_Cupboard.addfreshfruit(name, BBD, price,quantity);

        drinks >> name;
        drinks >> BBD;
        drinks >> quantity;
        drinks >> price;
        Drinks.addfreshfruit(name, BBD, price,quantity);
    }
    
    clubcard>>id;
    if (id>=1){
        clubcard>> firstname;
        clubcard>> secondname;
        clubcard>> address;
        clubcard>> points;
        Clubcard.addclubcard(id,firstname,secondname,address, points);
        clubcard>>id;

    }
    
    
    /*Fresh_Food.printAlltesco();
    Bakery.printAlltesco();
    Frozen_Food.printAlltesco();
    Food_Cupboard.printAlltesco();
    Drinks.printAlltesco();*/
    
    cout << endl;

    cout << "Welcome to Tesco" << endl;
    cout << "Please choose from one of the catergories below which you wish to choose yoour food from"<< endl;
    
    cout << "freshfood, bakery, frozenfood, foodcupboard and drinks"<< endl;
    
    cin >> ordered;
    biganswer="yes";
    
    while (biganswer=="yes"){
    
        if (ordered=="freshfood"){
        
        Fresh_Food.printAlltesco();
        
        cout << "would you like to select any foods if so select foods"<< endl;
        cin >> answer >> food;
        
        while (answer=="yes" || answer=="Yes"){
        
                findNode = Fresh_Food.findByName1(food);
                if (findNode==NULL){
                    cout << "this is invalid ID try again" << endl;
                }
            
            name=findNode->getName();
            BBD=findNode->getBBD1();
            price=findNode->getPrice();
            quantity=1;
            cost=cost+price;
            l1.recipttesco(name,BBD,price,quantity);
            name=findNode->getName();
            BBD=findNode->getBBD1();
            price=findNode->getPrice();
            quantity=(findNode->getQuantity())-1;
            Fresh_Food.removeNode(name);
            
            if(quantity>0){
                Fresh_Food.addfreshfruit(name, BBD, price,quantity);
            }
            if(quantity==0){
                cout<< "Sorry this product is sold out"<< endl;
            }
            
        
            cout << "would you like to select any foods if so select foods"<< endl;
            cin >> answer;
            
            if (answer=="yes"){
                cin >> food;
                if (answer=="no"){
                    ordered=" ";
                }
            }
        }
    }
        if (ordered=="bakery"){
        
            Bakery.printAlltesco();

            cout << "would you like to select any foods if so select foods"<< endl;
            cin >> answer >> food;
        
            while (answer=="yes" || answer=="Yes"){
            
                findNode = Bakery.findByName1(food);
                if (findNode==NULL){
                    cout << "this is invalid ID try again" << endl;
                }
                name=findNode->getName();
                BBD=findNode->getBBD1();
                price=findNode->getPrice();
                quantity=1;
                cost=cost+price;
                l1.recipttesco(name,BBD,price,quantity);
                name=findNode->getName();
                BBD=findNode->getBBD1();
                price=findNode->getPrice();
                quantity=(findNode->getQuantity())-1;
                Bakery.removeNode(name);
                
                if(quantity>0){
                    Bakery.addfreshfruit(name, BBD, price,quantity);
                }
                if(quantity==0){
                    cout<< "Sorry this product is sold out"<< endl;
                }
            
            
                cout << "would you like to select any foods if so select foods"<< endl;
                cin >> answer;
                if (answer=="yes"){
                    cin >> food;
                    if (answer=="no"){
                        ordered=" ";
                    }
                }
            }
        }
        if (ordered=="frozenfood"){
            
        
            Frozen_Food.printAlltesco();
    
            cout << "would you like to select any foods if so select foods"<< endl;
            cin >> answer >> food;
        
            while (answer=="yes" || answer=="Yes"){
        
                findNode = Frozen_Food.findByName1(food);
                if (findNode==NULL){
                    cout << "this is invalid ID try again" << endl;
                }
                name=findNode->getName();
                BBD=findNode->getBBD1();
                price=findNode->getPrice();
                quantity=1;
                cost=cost+price;
                l1.recipttesco(name,BBD,price,quantity);
                name=findNode->getName();
                BBD=findNode->getBBD1();
                price=findNode->getPrice();
                quantity=(findNode->getQuantity())-1;
                Frozen_Food.removeNode(name);
                
                if(quantity>0){
                Frozen_Food.addfreshfruit(name, BBD, price,quantity);
                }
                if(quantity==0){
                    cout<< "Sorry this product is sold out"<< endl;
                }
                
                cout << "would you like to select any foods if so select foods"<< endl;
                cin >> answer >> food;
                if (answer=="yes"){
                    cin >> food;
                    if (answer=="no"){
                        ordered=" ";
                    }
                }
            }
        }
        if (ordered=="foodcupboard"){
            
            Food_Cupboard.printAlltesco();
            
            cout << "would you like to select any foods if so select foods"<< endl;
            cin >> answer >> food;
            
            while (answer=="yes" || answer=="Yes"){
                
                findNode = Food_Cupboard.findByName1(food);
                if (findNode==NULL){
                    cout << "this is invalid ID try again" << endl;
                }
                name=findNode->getName();
                BBD=findNode->getBBD1();
                price=findNode->getPrice();
                quantity=1;
                cost=cost+price;
                l1.recipttesco(name,BBD,price,quantity);
                name=findNode->getName();
                BBD=findNode->getBBD1();
                price=findNode->getPrice();
                quantity=(findNode->getQuantity())-1;
                Food_Cupboard.removeNode(name);
                
                if(quantity>0){
                    Food_Cupboard.addfreshfruit(name, BBD, price,quantity);
                }
                if(quantity==0){
                    cout<< "Sorry this product is sold out"<< endl;
                }
                
                
                cout << "would you like to select any foods if so select foods"<< endl;
                cin >> answer >> food;
                if (answer=="yes"){
                    cin >> food;
                    if (answer=="no"){
                        ordered=" ";
                    }
                }
            }
        }
        if (ordered=="drinks"){
            
            Drinks.printAlltesco();
            
            cout << "would you like to select any foods if so select foods"<< endl;
            cin >> answer >> food;
            
            while (answer=="yes" || answer=="Yes"){
                
                findNode = Drinks.findByName1(food);
                if (findNode==NULL){
                    cout << "this is invalid ID try again" << endl;
                }
                name=findNode->getName();
                BBD=findNode->getBBD1();
                price=findNode->getPrice();
                quantity=1;
                cost=cost+price;
                l1.recipttesco(name,BBD,price,quantity);
                name=findNode->getName();
                BBD=findNode->getBBD1();
                price=findNode->getPrice();
                quantity=(findNode->getQuantity())-1;
                Drinks.removeNode(name);
                
                if(quantity>0){
                    Drinks.addfreshfruit(name, BBD, price,quantity);
                }
                if(quantity==0){
                    cout<< "Sorry this product is sold out"<< endl;
                }
                
                
                cout << "would you like to select any foods if so select foods"<< endl;
                cin >> answer >> food;
                if (answer=="yes"){
                    cin >> food;
                    if (answer=="no"){
                        ordered=" ";
                    }
                }
            }
        }
        cout <<"would you like to select another catergory and if so what one " << endl;
        cin >> biganswer;
        
        if (biganswer=="yes"){
            cin >> ordered;
            
        }
        
    }
    
    if (biganswer=="no"){
        cout << endl;
        cout << "Here is your shopping list:"<< endl;
        l1.printAlltesco();
        cout << "Total Shopping Cost: €"<< cost << endl;
        points=cost*100;
    }
    
    cout << "Would you like to delete anything from your shopping list:"<< endl;
    cin>> slist;
    if(slist=="yes"){
        cout << "what product do u want to delete:" << endl;
        cin>>deleted;
        findNode=l1.findByName1(deleted);
        money=findNode->getPrice();
        cost = cost-money;
        l1.removebyname(deleted);
        cout << "New Shopping list"<< endl;
        l1.printAlltesco();
        cout << "Total Shopping Cost: €"<< cost << endl;
        points=cost*100;
        
        
        
    }
    
    cout << "Are you an existing clubcard Holder" << endl;
    cin >> clubcardanswer;
    cout << endl;
    
    if (clubcardanswer=="yes") {
        cout << "Can I have your name please?" << endl;
        cin >> firstname >> secondname;
        findNode=Clubcard.findByName(firstname,secondname, points);
        points=(findNode->getPoints()) + points;
        id=findNode->getID();
        firstname=findNode->getFirstname();
        secondname=findNode->getSecondname();
        address=findNode->getAddress();
        findNode=Clubcard.removebyname(firstname);
        Clubcard.addclubcard(id,firstname,secondname,address, points);
        
        if (cost >=100){
            cost= 0.9*cost;
            
            cout << "Because you are an exisiting memeber you get 10 percent off" << endl;
            cout << "Total Shopping Cost: €"<< cost << endl;
        }
        
        cout <<"Would you like use your points"<< endl;
        cin >> pointsanswer;
        
        if (pointsanswer=="yes"){
            findNode=Clubcard.findByName(firstname,secondname, points);
            points=findNode->getPoints();
            id=findNode->getID();
            firstname=findNode->getFirstname();
            secondname=findNode->getSecondname();
            address=findNode->getAddress();
            findNode=Clubcard.removebyname(firstname);
            costoff=points/50;
            
            cost=cost-costoff;
            cout << "Your new Total Shopping Cost: €"<< cost << endl;
            
            points=0;
            Clubcard.addclubcard(id,firstname,secondname,address, points);
            
        }
        
    }
    
    if (clubcardanswer=="no"){
        cout << "Would you like to join?" << endl;
        cin >> joining;
        cout << endl;
        if (joining =="yes"){
            cout << "please enter your first name and second name" << endl;
            cin >> firstname>> secondname;
            cout << "Please enter your address with no spaces"<< endl;
            cin >> address;
            //id=(findNode->getID())+1;
            Clubcard.addclubcard(id,firstname,secondname,address, points);
    
            clubcard << findNode->getID() << findNode->getFirstname() << findNode->getSecondname() << findNode->getaAdress()<< findNode->getPoints;
            cout << "Now writing information to the file.\n";
            
           
        }
    }
    
    
    
    
    clubcard.close();
    //recipt<< l1.printAlltesco();
    //clubcard << Clubcard.printAlltesco();
    return 0;
}
