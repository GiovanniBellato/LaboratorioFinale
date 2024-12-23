#ifndef TIME_H_
#define TIME_H_

#include<stdexcept>

class Time{
private:
    int hour;
    int minute;
public:
    Time(int hour, int minute);
    Time getTime();
    void setTime(int hour, int minute);
    bool operator > (Time* time);
    bool operator >= (Time* time);
    bool operator < (Time* time);
    bool operator <= (Time* time);
    Time operator+(const Time& time) const;
    Time operator-(const Time& time) const;
    Time& operator = (Time& time);
    bool operator == (Time* time);
    void display();
};

#endif
