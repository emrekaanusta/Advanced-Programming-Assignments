#ifndef HW3_BOARD_H
#define HW3_BOARD_H

struct slot
{
    slot * next;
    slot * prev;
    CharStack slotStack;
    slot ()
    {}
};


class Board{


    public:{

        Board();
        bool noMove(char ch, int steps);
        int validMove(char ch, int startindex, int steps, int direction);
        void movePiece(int originIndex, int targetIndex);
        void printBoard();
        int evaluateGame();
        bool targetSlotFull(int slotindex);
        void destroySlot(int slotindex);
        void createSlotBegin(char ch, int num); // number of characters is num
        void createSlotEnd(char ch, int num);
        createEmptySlotEnd();
        clearBoard(); // clears board
    };

    private:{
        slot * head;
        slot * tail;
        int xCnt;
        int oCnt;
    };

};

#endif //HW3_BOARD_H
