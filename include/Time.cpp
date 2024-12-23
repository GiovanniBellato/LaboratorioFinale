#include "Time.h"

Time::Time(int hour, int minute){
    if(!(hour>=0 &&hour<24 && minute>=0 && minute<60))
        throw std::invalid_argument("Time is out of range");

    this -> hour = hour;
    this -> minute = minute;
}

Time Time::getTime() {
    return *this;
}

void Time::setTime(int hour, int minute) {
    if(!(hour>=0 &&hour<24 && minute>=0 && minute<60))
        throw std::invalid_argument("Time is out of range");

    this -> hour = hour;
    this -> minute = minute;
}

bool Time::operator > (Time* time) {
    if(hour > time->hour)
        return true;
    if(hour < time->hour)
        return false;
    if(minute > time->minute)
        return true;
    return false;
}

bool Time::operator >= (Time* time) {
    if(hour > time->hour)
        return true;
    if(hour < time->hour)
        return false;
    if(minute >= time->minute)
        return true;
    return false;
}

bool Time::operator < (Time* time) {
    if(hour > time->hour)
        return false;
    if(hour < time->hour)
        return true;
    if(minute < time->minute)
        return true;
    return false;
}

bool Time::operator <= (Time* time) {
    if(hour > time->hour)
        return false;
    if(hour < time->hour)
        return true;
    if(minute <= time->minute)
        return true;
    return false;
}
