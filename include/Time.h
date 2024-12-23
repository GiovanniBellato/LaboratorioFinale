#ifndef TIME_H
#define TIME_H

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
    Time operator + (Time* time);
    Time operator - (Time* time)
};

#endif
