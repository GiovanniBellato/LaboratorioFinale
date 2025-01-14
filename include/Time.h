#ifndef TIME_H_
#define TIME_H_

#include <stdexcept>
#include <iostream>
#include <string>
#include <fstream>

class Time{
private:
    int hour;
    int minute;
public:

    Time() : hour(0), minute(0) {} // Costruttore predefinito
    Time(int, int);

    //Metodi di elaborazione oggetti Time
    
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
    std::string toString() const;
    float toHour() const;
};

//Metodi di utility

//Trasforma una stringa in un oggetto time
Time toTime(std::string timeString);
//Funzione di print (terminale e log)
void print (std::string string);
//Funzione di cast da float a string
std::string floatString (float number);

#endif
