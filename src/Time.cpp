#include "Time.h"

Time::Time(int h, int m){
    if (!(h >= 0 && h < 24 && m >= 0 && m < 60)){
        throw std::invalid_argument("Invalid time values");
    }else{
    	hour = h;
    	minute = m;
    	}
    }

float Time::toHour() const {
    return (hour + (minute/60));
}

void Time::display() const {
    std::cout << hour <<":"<<minute;
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

bool Time::operator > (const Time& time) const {
    if(hour > time.hour)
        return true;
    if(hour < time.hour)
        return false;
    if(minute > time.minute)
        return true;
    return false;
}

bool Time::operator >= (const Time& time) const {
    return (*this > time || *this == time);
}

bool Time::operator < (const Time& time) const {
    return !(*this >= time);
}

bool Time::operator <= (const Time& time) const {
    return !(*this > time);
}

Time Time::operator + (const Time& time) const{
    int hour_t = hour + time.hour;
    int minute_t = 0;
    if(minute + time.minute >= 60){
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

Time Time::operator - (const Time& time) const{
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

Time& Time::operator = (const Time& time){
    hour = time.hour;
    minute = time.minute;
    return *this;
}

bool Time::operator == (const Time& time) const{
    return hour == time.hour && minute == time.minute;
}

Time toTime(std::string timeString)
{
    int hours = std::stoi(timeString.substr(0, 2));  // Estrai HH
    int minutes = std::stoi(timeString.substr(3, 2));  // Estrai MM

    Time temp(hours, minutes);
    return temp;
}
