//Emre Kaan Usta
#ifndef UNTITLED2_BOARD_H
#define UNTITLED2_BOARD_H

#include <string>
#include <iostream>
#include "Player.h"

using namespace std;

struct Node {
    string owner;
    Node* next;
    Node (string o, Node * p);
};

class Player;

class Board {

private:
    Node* first;

public:
    Board(int numSlots);
    ~Board();
    string who_owns(Node* node);
    Node* firstpointer();
    void display();
};
#endif //UNTITLED2_BOARD_H
