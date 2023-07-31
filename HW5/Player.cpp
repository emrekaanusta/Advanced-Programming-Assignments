//Emre Kaan Usta

#include "Player.h"
#include "Board.h"
#include <iostream>

Player::Player(Board& b, const string& n, int initialCapital) :
    board(b)
{   name = n;
    balance = initialCapital;
    position = board.firstpointer();
}

int Player::move(int steps) {
    int a = 0;
    for (int i = 0; i < steps; ++i) {
        position = position->next;
        if (position == board.firstpointer()) {
            // balance += 1000; // player has passed the starting slot
            a = 1;
        }
    }
    return a;
}

Node* Player::where_am_I() const {
    return position;
}

void Player::pay_to_player(Player& otherPlayer, int money) {
    balance -= money;
    otherPlayer.deposit_money(money);
}

int Player::get_balance() const {
    return balance;
}

void Player::deposit_money(int amount) {
    balance += amount;
}

void Player::buy_slot(int price) {
    if (balance >= price) {
        position->owner = name;
    }
    balance -= price;
}

bool Player::is_bankrupt() const {
    return balance < 0;
}

void Player::display() const {
    string output = "", spaces = "";
    int counter = 0;
    Node* a = board.firstpointer();
    while (a != position){
        a = a->next;
        counter++ ;
    }
    for (int i = 0; i < counter; i ++){
        spaces += "      ";
    }
    output += spaces;
    output += name;
    output += " ";
    output += to_string(balance);
    cout << output << endl;
}