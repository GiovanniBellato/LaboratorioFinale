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
    Time(int h, int m) : hour(h), minute(m) {
        if (h < 0 || h >= 24 || m < 0 || m >= 60) {
            throw std::invalid_argument("Invalid time value");
        }
    }
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
};


#endif
