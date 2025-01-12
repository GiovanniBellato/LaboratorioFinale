#ifndef TIME_H_
#define TIME_H_

#include<stdexcept>
#include <iostream>

class Time{
private:
    int hour;
    int minute;
public:

    Time() : hour(0), minute(0) {} // Costruttore predefinito
    Time(int, int);

    Time getTime();
    void setTime(int hour, int minute);
    bool operator > (const Time& time) const;
    bool operator >= (const Time& time) const;
    bool operator < (const Time& time) const;
    bool operator <= (const Time& time) const;
    Time operator + (const Time& time) const;
    Time operator - (const Time& time) const;
    Time& operator = (const Time& time);
    bool operator == (const Time& time) const;
    void display() const;
    float toHour() const;
    Time toTime(std::string timeString);
};


#endif
