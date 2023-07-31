#include "IntQueueHW6.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <mutex>
#include <vector>

using namespace std;
mutex myMutex, myMutexCout;


void playerThread(int ID, struct tm * ptm,  IntQueueHW6 & myQueue, vector<int> & threads) {

    this_thread::sleep_until(chrono::system_clock::from_time_t(::mktime(ptm)));

    myMutex.lock(); // Lock the mutex

    time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now());
    struct tm *ptt = new struct tm;
    localtime_s(ptt, &tt);

    if (!myQueue.isFull()) {
        myQueue.enqueue(ID);
        threads.push_back(ID);
        myMutexCout.lock();
        cout << "Player " << ID << " captured a chair at " << put_time(ptt, "%X")<< "." << endl;
        myMutexCout.unlock();
    }

    else {
        myMutexCout.lock();
        cout << "Player " << ID << " couldn't capture a chair." << endl;
        myMutexCout.unlock();
    }

    myMutex.unlock(); // Unlock the mutex
}


int main() {
    int player;
    cout << "Welcome to Musical Chairs game!" << endl;
    cout << "Enter the number of players in the game: " << endl;
    cin >> player;

    cout << "Game Start!" << endl << endl;

    vector<int> remaining;
    for (int k = 0; k < player; k++){
        remaining.push_back(k);
    }

    int c = player;
    for (int a = 0; a < c - 1; a++){
        time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now());
        struct tm *ptm = new struct tm;
        localtime_s(ptm, &tt);
        cout << "Time is now " << put_time(ptm, "%X") << endl;
        // current time is displayed

        if (ptm->tm_sec + 2 < 60){   // if 2 minute later is smaller than 60
            ptm->tm_sec += 2;
        }
        else {  // if minute is 58-59
            int a = 2 - (60 - ptm->tm_sec);
            ptm->tm_sec = a;
            ptm->tm_min++;
        }
        // time is calculated


        IntQueueHW6 myQueue(player - 1);
        vector<int> threads;
        thread threadList[player];
        for (int k = 0; k < player; k++){  // the amount of players left
            int d = remaining[k];
            threadList[k]  =  thread(playerThread, d, ptm, ref(myQueue), ref(threads));
        }
        for (int k = 0; k < player; k++){  // the amount of players left
            threadList[k].join();
        }

        player--;
        cout << "Remaining players are as follows: ";
        for (int i = 0; i < threads.size(); i ++){
            cout << threads[i] << " ";
        }
        cout << endl << endl;
        if (threads.size() == 1){
            cout << "Game over!" << endl;
            cout << "Winner is Player " << threads[0] << "!";
        }
        remaining = threads;

    }


}
