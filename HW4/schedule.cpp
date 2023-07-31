// Emre Kaan Usta

#include <iostream>
#include <string>
#include "schedule.h"

using namespace std;

string** Schedule :: get_data() const{
    return data;
}

int Schedule :: get_timeslots() const{

    return this->time_slots;
}

Schedule :: Schedule (int column){
    data = new string*[7];
    time_slots = column;
    for (int i = 0; i < 7; i++) {
        data[i] = new string[column];
        for (int j = 0; j < column; j++) {
            data[i][j] = "free";
        }
    }
}

Schedule :: ~Schedule(){
    for (int i = 0; i < 7; i++) {
        delete[] data[i];
    }
    delete[] data;
}

Schedule :: Schedule() {
    time_slots = 0;
    data = new string*[7];

    for (int i = 0; i < 7; i++) {
        data[i] = NULL;
    }

}

Schedule :: Schedule(const Schedule & temp) {  // deep coppy
    time_slots = temp.time_slots;
    data = new string*[7];

    for (int i = 0; i < 7; i++) {
        data[i] = new string[time_slots];
        for (int j = 0; j < time_slots; j++) {
            data[i][j] = temp.data[i][j];
        }
    }
}

const Schedule & Schedule :: operator = (const Schedule& rhs) {
    if (this == &rhs) {
            return *this;
    }

    for (int i = 0; i < 7; i++) {
        delete[] data[i];
    }
    delete[] data;

    time_slots = rhs.time_slots;
    data = new string*[7];

    for (int i = 0; i < 7; i++) {
        data[i] = new string[time_slots];
        for (int j = 0; j < time_slots; j++) {
            data[i][j] = rhs.data[i][j];
        }
    }
    return *this;
}

const Schedule  operator + (const Schedule& lhs, const Days & rhs){
    Schedule copy(lhs);
    for (int i = 0; i < 7; i++) {
        if (i == rhs) {
            for (int j = 0; j < copy.get_timeslots(); j++) {
                copy[Days(i)][j] = "busy";
            }
        }
    }
    return copy;
}

const Schedule  operator + (const Schedule& lhs, const int & rhs){
    Schedule copy(lhs);
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < copy.get_timeslots(); j++) {
            if (j == rhs) {
                copy[Days(i)][j] = "busy";
            }
        }
    }
    return copy;
}

const Schedule  operator + (const Schedule& lhs, const Schedule & rhs){
    Schedule copy(lhs);
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < lhs.get_timeslots(); j++) {
            if (rhs.get_data()[i][j] == "busy" or lhs.get_data()[i][j] == "busy"){
                copy[Days(i)][j] = "busy";
            }
            else {
                copy[Days(i)][j] = "free";
            }
        }
    }
    return copy;
}

bool Schedule :: operator < (const Schedule &rhs) {
    int rightbusy = 0, leftbusy = 0;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < this->time_slots; j++) {
            if (this->data[i][j] == "busy") {
                leftbusy++;
            }
        }
        for (int j = 0; j < rhs.time_slots; j++) {
            if (rhs.data[i][j] == "busy") {
                rightbusy++;
            }
        }
    }
    return leftbusy < rightbusy;
}

Schedule Schedule :: operator * (const Schedule & rhs){
    Schedule copy(*this);
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < rhs.get_timeslots(); j++) {
            if (rhs.get_data()[i][j] == "free" or copy.get_data()[i][j] == "free"){
                copy.get_data()[i][j] = "free";
            }
            else {
                copy.get_data()[i][j] = "busy";
            }
        }
    }
    return copy;
}

string* Schedule :: operator [](const Days & rhs) const{
    for (int a = 0; a < 7; a++){
        if (a == rhs){
            return data[a];
        }
    }
    return data[0];
}

ostream& operator << (ostream &output, const Schedule & rhs){

    for (int a = 0; a < 7; a++){
         if (Days(a) == Monday){
            output << "Mo: ";
         }
         else if (Days(a) == Tuesday){
            output << "Tu: ";
         }
         else if (Days(a) == Wednesday){
            output << "We: ";
         }
         else if (Days(a) == Thursday){
            output << "Th: ";
         }
         else if (Days(a) == Friday){
            output << "Fr: ";
         }
         else if (Days(a) == Saturday){
            output << "Sa: ";
         }
         else if (Days(a) == Sunday){
            output << "Su: ";
         }
         for (int k = 0; k < rhs.get_timeslots(); k ++){
             output << rhs.get_data()[a][k];
             if (k < rhs.get_timeslots() - 1){
                 output << " ";
             }
         }
         cout << endl;

     }
    return output;
}

ostream& operator << (ostream &output, const Days & rhs){
    if (rhs == Monday){
        output << "Monday";
    }
    else if (rhs == Tuesday){
        output << "Tuesday";
    }
    else if (rhs == Wednesday){
        output << "Wednesday";
    }
    else if (rhs == Thursday){
        output << "Thursday";
    }
    else if (rhs == Friday){
        output << "Friday";
    }
    else if (rhs == Saturday){
        output << "Saturday";
    }
    else if (rhs == Sunday){
        output << "Sunday";
    }
    return output;
}


