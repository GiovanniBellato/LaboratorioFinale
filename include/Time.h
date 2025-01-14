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
    Time() : hour(0), minute(0) {} // COSTRUTTORE PREDEFINITO
    Time(int, int);

    //METODI DI ELABORAZIONE OGGETTI TIME

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

    std::string toString() const;  //METODO DI RAPPRESENTAZIONE
    float toHour() const; //CONVERSIONE TIME -> FLOAT
};

//FUNZIONI HELPER - <NON COLLEGATE A 'TIME' CONCETTUALMENTE>

//STRINGA -> OGGETTO DI TIPO TIME
Time toTime(std::string timeString);

//FUNZIONE DI STAMPA (TERMINALE E LOG)
void print (std::string string);

//FLOAT -> STRINGA
std::string floatString (float number);

#endif
