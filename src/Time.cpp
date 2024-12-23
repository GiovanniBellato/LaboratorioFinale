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

Time Time::operator + (Time* time){
    Time new_time;
    new_time.hour = hour + time->hour;
    if(minute + time->minute > 60){
        new_time.hour ++;
        new_time.minute = (minute + time->minute) - 60;
    }
    else{
        new_time.minute = minute + time->minute;
    }
    if(new_time.hour > 23)
        throw std::invalid_argument("Time is out of range");
    return new_time;
}

Time Time::operator - (Time* time){
    Time new_time;
    new_time.hour = hour - time->hour;
    new_time.minute = minute - time->minute;
    if(new_time.minute < 0){
        new_time.hour --;
        new_time.minute += 60;
    }
    if(time.hour < 0)
        new_time.hour = hour;
    return new_time;
}

Time& Time::operator = (const Time& time){
    hour = time->hour;
    minute = time->minute;
    return *this;
}

bool Time::operator == (Time* time){
    if(hour != time->hour)
        return false;
    if(minute != time->minute)
        return false;
    return true;
}

