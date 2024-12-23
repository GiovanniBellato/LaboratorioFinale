#include "Time.h"

void Time::display(){
	std::cout << "  " << hour <<":"<<minute<<"  ";
}

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

Time Time::operator+(const Time& time) const{
    int hour_t = hour + time.hour;
    int minute_t = 0;
    if(minute + time.minute > 60){
        hour_t++;
        minute_t = (minute + time.minute) - 60;
    }
    else{
        minute_t = (minute + time.minute);
    }
    if(hour_t > 23)
        throw std::invalid_argument("Time is out of range");
    return Time(hour_t, minute_t);
}

Time Time::operator-(const Time& time) const{
    int hour_t, minute_t;
    hour_t = hour - time.hour;
    minute_t = minute - time.minute;
    if(minute_t < 0){
        hour_t --;
        minute_t += 60;
    }
    if(hour_t < 0){
        hour_t = hour;
        minute_t = minute;
    }
    return Time(hour_t, minute_t);
}

Time& Time::operator = (Time& time){
    hour = time.hour;
    minute = time.minute;
    return *this;
}

bool Time::operator == (Time* time){
    if(hour != time->hour)
        return false;
    if(minute != time->minute)
        return false;
    return true;
}

