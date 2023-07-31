#include <iostream>
#include <string>
#include "feedback.h"

using namespace std;

struct node
        {
    string digit;
    node * next;
    node (){

    };
};
void deleteNode(node* & head, char digit) {
    node* current = head;
    node* prev = NULL;

    while (current != NULL) {
        if (current->digit[0] == digit) {
            // Remove the current node
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            current = prev == NULL ? head : prev->next;
        } else {
            // Move to the next node
            prev = current;
            current = current->next;
        }
    }
}
void printer( node* head){
    node* temp = head;
    while (temp != NULL)
    {
        cout << temp -> digit << " " ;
        temp = temp->next;
    }
}

bool search( node* head, char a)
{
    node* current = head;
    while (current != NULL)
    {
        if (current->digit[0] == a)
            return true;
        current = current->next;
    }
    return false;
}
// i am taking this code from pointers-linked lists - 2 presentation and changing it

int guess1 (node* head){
    for (int i = 0; i < 10; i++){
        if (!(search(head, to_string(i)[0]))){
            return i;
        }
    }
    return 0;
}

void AddInOrder(node * & head, char newkey)
{
    node *  ptr = head;   // loop variable

    if (head == NULL || newkey < head->digit[0])                // if the next pointer is bigger than digit or null
    {
        node * temp = new node;  //node to be inserted
        temp->digit = newkey;
        temp->next = head;
        head = temp;   //connect the rest //new head
    }

    // check node one ahead so we don't pass!
    else{
        while (ptr->next != NULL && ptr->next->digit[0] < newkey) {
            ptr = ptr->next;
        }
        //now insert new node with newkey after where ptr points to
        node * temp = new node;  //node to be inserted
        temp->digit = newkey;
        temp->next = ptr->next; //connect the rest
        ptr->next = temp;
    }
}

// end of taking code

int sizer(node* head){
    node* current = head;
    int a = 0;
    while (current != NULL)
    {
        a++;
        current = current->next;
    }
    return a;
}


int main() {
    string  guess;
    int game_id;

    node *possibles[3] = {NULL, NULL, NULL};
    node *impossibles[3] = {NULL, NULL, NULL};

    // six linked lists
    for (int i = 0; i < 3; i++) {
        // Possible digits linked list
        node *possiblesHead = NULL;
        possibles[i] = possiblesHead;

        // Impossible digits linked list
        node *impossiblesHead = NULL;
        impossibles[i] = impossiblesHead;
    }

    // now we have 6 linked lists of 2 built in arrays that we will keep the possible and impossible numbers

    cout << "Please enter a game ID." << endl;
    cin >> game_id;
    /* cout << "Enter your guess." << endl;
    cin >> guess;
    while (guess.length() > 3 or (guess[0] == guess[1]) or (guess[0] == guess[2]) or (guess[2] == guess[1]) or
           (guess[0] != '0' and guess[0] != '1' and guess[0] != '2' and guess[0] != '3' and guess[0] != '4' and
            guess[0] != '5' and guess[0] != '6' and guess[0] != '7' and guess[0] != '8' and guess[0] != '9') or
           (guess[1] != '0' and guess[1] != '1' and guess[1] != '2' and guess[1] != '3' and guess[1] != '4' and
            guess[1] != '5' and guess[1] != '6' and guess[1] != '7' and guess[1] != '8' and guess[1] != '9') or
           (guess[2] != '0' and guess[2] != '1' and guess[2] != '2' and guess[2] != '3' and guess[2] != '4' and
            guess[2] != '5' and guess[2] != '6' and guess[2] != '7' and guess[2] != '8' and guess[2] != '9')) {
        cout << "Invalid guess. Enter your guess." << endl;
        cin >> guess;
    }

    string feedback = get_the_feedback(guess, game_id);  */

    // first 100's
    while(!(sizer(impossibles[0]) == 9 and sizer(impossibles[1]) == 9 and sizer(impossibles[2]) == 9 )) {
        cout << "Enter your guess." << endl;
        cin >> guess;
        while (guess.length() > 3 or (guess[0] == guess[1]) or (guess[0] == guess[2]) or (guess[2] == guess[1]) or
               (guess[0] != '0' and guess[0] != '1' and guess[0] != '2' and guess[0] != '3' and guess[0] != '4' and
                guess[0] != '5' and guess[0] != '6' and guess[0] != '7' and guess[0] != '8' and guess[0] != '9') or
               (guess[1] != '0' and guess[1] != '1' and guess[1] != '2' and guess[1] != '3' and guess[1] != '4' and
                guess[1] != '5' and guess[1] != '6' and guess[1] != '7' and guess[1] != '8' and guess[1] != '9') or
               (guess[2] != '0' and guess[2] != '1' and guess[2] != '2' and guess[2] != '3' and guess[2] != '4' and
                guess[2] != '5' and guess[2] != '6' and guess[2] != '7' and guess[2] != '8' and guess[2] != '9')) {
            cout << "Invalid guess. Enter your guess." << endl;
            cin >> guess;
        }

        string feedback = get_the_feedback(guess, game_id);
        if (feedback[0] == 'R') {   // does not exist in the number
            if (!(search(impossibles[0], guess[0]))) {           // if not in lists
                AddInOrder(impossibles[0], guess[0]);
            }
            if (!(search(impossibles[1], guess[0]))) {
                AddInOrder(impossibles[1], guess[0]);
            }
            if (!(search(impossibles[2], guess[0]))) {
                AddInOrder(impossibles[2], guess[0]);
            }
            if(search(possibles[0], guess[0])){
                deleteNode(possibles[0], guess[0]);}
            if(search(possibles[1], guess[0])){
                deleteNode(possibles[1], guess[0]);}
            if(search(possibles[2], guess[0])){
                deleteNode(possibles[2], guess[0]);}
        }
        if (feedback[0] == 'Y') {        // wrong place
            if (!(search(impossibles[0], guess[0]))) {           // if not in lists
                AddInOrder(impossibles[0], guess[0]);
            }
            if(search(possibles[0], guess[0])){
                deleteNode(possibles[0], guess[0]);}

            if (!(search(impossibles[1], guess[0]))) {
                if (!(search(possibles[1], guess[0]))) {
                    AddInOrder(possibles[1], guess[0]);
                }
            }
            if (!(search(impossibles[2], guess[0]))) {
                if (!(search(possibles[2], guess[0]))) {
                    AddInOrder(possibles[2], guess[0]);
                }
            }
        }
        if (feedback[0] == 'G') {            // correct place and number
            if (!(search(possibles[0], guess[0]))) {           // if not in lists
                AddInOrder(possibles[0], guess[0]);
            }                   // add others to impossibles lists
            for (int i = 0; i < 10; i++) {
                int a = i;
                if ((to_string(a)[0]) != guess[0]) {
                    if (!(search(impossibles[0], to_string(a)[0]))) {        // if not in lists
                        AddInOrder(impossibles[0], to_string(a)[0]);
                    }
                }
            }
            if (!(search(impossibles[1], guess[0]))) {
                AddInOrder(impossibles[1], guess[0]);
            }
            if (!(search(impossibles[2], guess[0]))) {
                AddInOrder(impossibles[2], guess[0]);
            }

            if(search(possibles[1], guess[0])){
                deleteNode(possibles[1], guess[0]);}
            if(search(possibles[2], guess[0])){
                deleteNode(possibles[2], guess[0]);}
        }

        // 10s

        if (feedback[1] == 'R') {   // does not exist in the number
            if (!(search(impossibles[0], guess[1]))) {           // if not in lists
                AddInOrder(impossibles[0], guess[1]);
            }
            if (!(search(impossibles[1], guess[1]))) {
                AddInOrder(impossibles[1], guess[1]);
            }
            if (!(search(impossibles[2], guess[1]))) {
                AddInOrder(impossibles[2], guess[1]);
            }
            if(search(possibles[0], guess[1])){
                deleteNode(possibles[0], guess[1]);}
            if(search(possibles[1], guess[1])){
                deleteNode(possibles[1], guess[1]);}
            if(search(possibles[2], guess[1])){
                deleteNode(possibles[2], guess[1]);}
        }
        if (feedback[1] == 'Y') {        // wrong place
            if (!(search(impossibles[1], guess[1]))) {           // if not in lists
                AddInOrder(impossibles[1], guess[1]);
            }
            if(search(possibles[1], guess[1])){
                deleteNode(possibles[1], guess[1]);}

            if (!(search(impossibles[0], guess[1]))) {
                if (!(search(possibles[0], guess[1]))) {
                    AddInOrder(possibles[0], guess[1]);
                }
            }
            if (!(search(impossibles[2], guess[1]))) {
                if (!(search(possibles[2], guess[1]))) {
                    AddInOrder(possibles[2], guess[1]);
                }
            }
        }
        if (feedback[1] == 'G') {            // correct place and number
            if (!(search(impossibles[1], guess[1]))) {
                if (!(search(possibles[1], guess[1]))) {           // if not in lists
                    AddInOrder(possibles[1], guess[1]);
                }
            }
            for (int i = 0; i < 10; i++) {
                int a = i;

                if ((to_string(a)[0]) != guess[1]) {
                    if (!(search(impossibles[1], to_string(a)[0]))) {        // if not in lists
                        AddInOrder(impossibles[1], to_string(a)[0]);
                    }
                }
            }
            if (!(search(impossibles[0], guess[1]))) {
                AddInOrder(impossibles[0], guess[1]);
            }
            if (!(search(impossibles[2], guess[1]))) {
                AddInOrder(impossibles[2], guess[1]);
            }

            if(search(possibles[0], guess[1])){
                deleteNode(possibles[0], guess[1]);}
            if(search(possibles[2], guess[1])){
                deleteNode(possibles[2], guess[1]);}
        }

        // 0's

        if (feedback[2] == 'R') {   // does not exist in the number
            if (!(search(impossibles[0], guess[2]))) {           // if not in lists
                AddInOrder(impossibles[0], guess[2]);
            }
            if (!(search(impossibles[1], guess[2]))) {
                AddInOrder(impossibles[1], guess[2]);
            }
            if (!(search(impossibles[2], guess[2]))) {
                AddInOrder(impossibles[2], guess[2]);
            }
            if(search(possibles[0], guess[2])){
                deleteNode(possibles[0], guess[2]);}
            if(search(possibles[1], guess[2])){
                deleteNode(possibles[1], guess[2]);}
            if(search(possibles[2], guess[2])){
                deleteNode(possibles[2], guess[2]);}
        }
        if (feedback[2] == 'Y') {        // wrong place
            if (!(search(impossibles[2], guess[2]))) {           // if not in lists
                AddInOrder(impossibles[2], guess[2]);
            }
            if(search(possibles[2], guess[2])){
                deleteNode(possibles[2], guess[2]);}

            if (!(search(impossibles[0], guess[2]))) {
                if (!(search(possibles[0], guess[2]))) {
                    AddInOrder(possibles[0], guess[2]);
                }
            }
            if (!(search(impossibles[1], guess[2]))) {
                if (!(search(possibles[1], guess[2]))) {
                    AddInOrder(possibles[1], guess[2]);
                }
            }

        }
        if (feedback[2] == 'G') {            // correct place and number
            if (!(search(impossibles[2], guess[1]))) {
                if (!(search(possibles[2], guess[2]))) {           // if not in lists
                    AddInOrder(possibles[2], guess[2]);
                }
            }
            for (int i = 0; i < 10; i++) {
                int a = i;
                if ((to_string(a)[0]) != guess[2]) {
                    if (!(search(impossibles[2], to_string(a)[0]))) {        // if not in lists
                        AddInOrder(impossibles[2], to_string(a)[0]);
                    }
                }
            }
            if (!(search(impossibles[0], guess[2]))) {
                AddInOrder(impossibles[0], guess[2]);
            }
            if (!(search(impossibles[1], guess[2]))) {
                AddInOrder(impossibles[1], guess[2]);
            }

            if(search(possibles[0], guess[2])){
                deleteNode(possibles[0], guess[2]);}
            if(search(possibles[1], guess[2])){
                deleteNode(possibles[1], guess[2]);}
        }

        cout << "Linked lists: " << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Slot: " << i + 1 << endl;
            cout << "Impossibles: ";
            printer(impossibles[i]);
            cout << endl;
            cout << "Possibles: ";
            printer(possibles[i]);
            cout << endl << endl;
        }

    }
    int slot1 = guess1(impossibles[0]), slot2 = guess1(impossibles[1]), slot3 = guess1(impossibles[2]);
    string secretnum = to_string(slot1) + to_string(slot2) + to_string(slot3);
    cout << "The secret number is: " << secretnum << endl;
    cout << "Congrats! Now, deleting the lists..." ;
    return 0;
}