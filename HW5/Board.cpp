//Emre Kaan Usta
#include <string>
#include <iostream>
#include "Board.h"


Node::Node(string o, Node* p) {
    owner = o;
    next = p;
}

Board::Board(int numSlots) {
    Node* prev = NULL;
    for (int i = 0; i < numSlots; ++i) {
        Node* p = new Node("None", NULL);
        if (prev != NULL) {
            prev->next = p;
        }
        else {
            first = p;
        }
        prev = p;
    }
    prev->next = first; // circular
}

Board::~Board(){
    Node* p = first;
    if (p != nullptr) {
        Node* q = p->next;
        while (q != first) {
            delete p;
            p = q;
            q = p->next;
        }
        delete p; // delete last node
    }
}

string Board::who_owns (Node* s){
    return s->owner;
}

Node* Board::firstpointer (){
    return first;
}

void Board :: display(){
    Node* a = first;
    cout << a->owner;
    if (a->owner != "None"){
        cout << " ";
    }
    a = a->next;
    int counter = 0;
    while (a != first){
        cout << "->" << a->owner;
        if (a->owner != "None"){
            cout << " ";
        }
        counter ++;
        a = a-> next;
    }
    Node* k = first->next;
    int keeper = 0;
    while (k != first){
        keeper ++;
        k = k->next;
    }
    cout << endl;
    cout << "^    ";
    for (int i = 0; i < keeper; i++){
        if (i == keeper -1){
            cout << "    |";
        }
        else{
            cout << "      ";
        }
    }
    cout << endl;
    cout << "|----";
    for (int i = 0; i < keeper; i++){
        if (i == keeper -1){
            cout << "<---v";
        }
        else{
            cout << "<-----";
        }
    }
    cout << endl;
}