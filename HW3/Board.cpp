#include "intstack.h"
#include

Board :: Board(){
    head nullptr;
    tail nullptr;
    xCnt = 0;
    oCnt = 0;
}

bool Board ::  noMove(char ch, int steps);{
    slot * temp = head;
    slot * temp2;
    char tempch = ch;
    bool a;
    while (temp != null){
        a = temp.pop(ch);
        if (a){
            temp.push(ch);
            if (tempch == ch){
                temp2 = temp;
                for (int i = 0; i < steps & temp2 != nullptr ; i ++){
                    temp2 = temp2 -> next;
                }
                if (temp2 ! = nullptr){
                    if (temp2->slotStack.isEmpty()){
                        return false;
                    }
                }
            }
            if (tempch == ch){
                temp2 = temp;
                for (int i = 0; i < steps & temp2 != nullptr ; i ++){
                    temp2 = temp2 -> prev;
                }
                if (temp2 ! = nullptr){
                    if (temp2->slotStack.isEmpty()){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int Board :: validMove(char ch, int startindex, int steps, int direction){
    slot* current = head;
    for (int i = 0; i < startIndex; i++) {
        current = current->next;   // start index slot
    }

    if (startindex < 0 or startindex > head.size() - 1){
        return 1;
    }

    if (direction == '0'){
        steps = -steps;
    }
    int targetindex = startindex + steps;

    slot* target = head;
    for (int i = 0; i < startIndex; i++) {
        target = target->next;   // target index slot
    }

    if (startindex + steps > head.size() - 1  or startindex + steps < head.size() - 1){  // out of range
        return 2;
    }


    if (target->charStack.isEmpty() == false) {
        return 3;
    }
    else {
        if (target.pop(ch)){  // if the slot is filled with the desired charachters
            target.push(ch);
        }
        else {
            return 3;
        }
    }

    if (current.pop(ch)){  // if the slot is filled with the desired charachters
        current.push(ch);
    }
    else {
        return 4;
    }
}

void Board :: movePiece(int originIndex, int targetIndex){  // parameters are absent
    slot* slot1 = head;
    slot* slot2 = head;
    for (int i = 0; i < sourceIndex; i++) {
        slot1 = slot1->next;
    }

    for (int i = 0; i < targetIndex; i++) {
        slot2 = slot2->next;
    }

    // Pop the piece from the source slot and push it to the target slot
    char piece;
    slot1->slotStack.pop(piece);
    slot2->slotStack.push(piece);
}

void Board :: printBoard(){
    void Board::printBoard() {
        string line1 = "", line2 = "", line3 = "", line4 = "";

        // iterate through each slot in the board
        slot* currentSlot = head;
        while (currentSlot != nullptr) {
            // get the top character of the current slot's stack
            char topChar;
            currentSlot->slotStack.pop(topChar);

            // add the character to the appropriate line
            if (topChar == 'X') {
                line1 += topChar;
                line2 += topChar;
                line3 += topChar;
                line4 += ' ';
            } else if (topChar == 'O') {
                line1 += ' ';
                line2 += topChar;
                line3 += topChar;
                line4 += topChar;
            } else { // empty slot
                line1 += ' ';
                line2 += ' ';
                line3 += ' ';
                line4 += '^';
            }

            // move to the next slot
            currentSlot = currentSlot->next;
        }

        // print out the lines of the board
        cout << line1 << endl;
        cout << line2 << endl;
        cout << line3 << endl;
        cout << line4 << endl;
    }
}

int Board :: evaluateGame();{
    if (xCnt > oCnt){
        return 2;
    }
    if (xCnt < oCnt){
        return 1;
    }
    if (xCnt == oCnt){
        return 3;
    }
}

bool Board :: targetSlotFull(int slotindex){
    slot* current = head;
    for (int i = 0; i < slotindex; i++) {
        current = current->next;
    }
    if (current->charStack.isFull()){
        return 1;
    }
    return 0;
}

void Board :: destroySlot(int slotindex){
    slot * indexslot ;
    for (int i = 0; i < slotindex; i++){
        indexslot = indexslot -> next;
    }
    slot* previous = indexslot -> prev;
    slot* next = indexslot -> next;
    delete indexslot;
    next = previous->next;
}

void Board ::  createSlotBegin(char ch, int num){
    slot * newSlot = new slot();
    newSlot->slotStack.push(ch);
    if (head == nullptr) {
        head = newSlot;
        tail = newSlot;
    }
    else {
        newSlot->next = head;
        head->prev = newSlot;
        head = newSlot;
    }
    if (ch == 'X'){
        xCnt += num;
    }
    else {
        oCnt += num;
    }
}

void Board :: createSlotEnd(char ch, int num){
    slot * newSlot = new slot();
    newSlot->slotStack.push(ch);
    newSlot->prev = tail;
    if (tail != nullptr) {
        tail->next = newSlot;
    } else {
        head = newSlot;
    }
    tail = newSlot;
    if (ch == 'X') {
        xCnt += num;
    } else {
        oCnt += num;
    }
}

void Board :: createEmptySlotEnd(){
    slot * newSlot = new slot();
    newSlot->prev = tail;
    if (tail != nullptr) {
        tail->next = newSlot;
    } else {
        head = newSlot;
    }
    tail = newSlot;
}

void Board :: clearBoard(){
    slot * current = head;
    while (current != nullptr) {
        slot * temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    xCnt = 0;
    oCnt = 0;
}