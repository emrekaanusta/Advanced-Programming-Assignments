//Emre Kaan Usta
#ifndef UNTITLED2_PLAYER_H
#define UNTITLED2_PLAYER_H

#include "Board.h"
#include <string>
#include <iostream>

using namespace std;

class Board;

class Node;

class Player {

private:
    string name;
    int balance;
    Node* position;
    Board& board; // reference to the shared board object

public:
    Player(Board& board, const string& name, int initialCapital);
    int move(int steps);
    Node* where_am_I() const;
    void pay_to_player(Player& otherPlayer, int money);
    int get_balance() const;
    void deposit_money(int money);
    void buy_slot(int price);
    bool is_bankrupt() const;
    void display() const;
};


#endif //UNTITLED2_PLAYER_H
