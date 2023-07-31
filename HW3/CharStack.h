#ifndef CHARSTACK_H
#define CHARSTACK_H

class CharStack
{
private:
    char *stackArray{};
    int stackSize{};
    int top{};

public:
    CharStack(const CharStack&);
    CharStack& operator=(const CharStack &rhs);
    CharStack(int);
    ~CharStack();
    CharStack();
    bool push(char);
    bool pop(char &);
    bool isFull(void);
    bool isEmpty(void);
};

#endif