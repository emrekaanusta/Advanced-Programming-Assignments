#ifndef UNTITLED1_SCHEDULE_H
#define UNTITLED1_SCHEDULE_H

#include <string>
using namespace std;
enum Days {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};


class Schedule{
private:
        int time_slots;
        string** data;

public:

    string** get_data() const;
    int get_timeslots() const;
    Schedule(); // DEFAULT constructor
    Schedule(const Schedule & temp);
    Schedule(int c);
    ~Schedule();



    const  Schedule & operator = (const Schedule & rhs);

    Schedule operator * (const Schedule & rhs);

    string *  operator [] (const Days & rhs) const;

    bool operator < (const Schedule &rhs);

};

const Schedule   operator +  (const Schedule& lhs, const Days & rhs) ;

const Schedule   operator + (const Schedule& lhs, const int & rhs);

const Schedule   operator + (const Schedule& lhs, const Schedule & rhs);

ostream& operator << (ostream &output, const Schedule & rhs);

ostream& operator << (ostream &input, const Days & rhs);

#endif //UNTITLED1_SCHEDULE_H
