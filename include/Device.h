#ifndef DEVICE_H_
#define DEVICE_H_

#include "Time.h"

class Device{
private:
    std::string name;        //NOME DISPOSITIVO
    int id;                  //ID UNICO
    float power;             //POTENZA IN KWH
    float total_power;       //CONSUMO TOTALE EFFETTUATO
    bool isOn;               //STATO DEL DISPOSITIVO
    Time timer_on;           //TIMER DI ACCENSIONE
    bool timer = false;      //STATO DEL TIMER  

public:
    Device() : timer_on(0, 0) {}
    virtual ~Device() = default;

    //GESTIONE ACCENSIONE/SPEGNIMENTO E DEL TEMPO
    virtual void update(Time currentTime) = 0;   
    virtual void turnOn(Time) = 0;  
    virtual void turnOff(Time) = 0; 

    //FUNZIONE DI OTTENIMENTO DATI
    virtual std::string getName() const = 0;
    virtual float getPower() = 0;
    virtual float getConsumption(Time) = 0;

    //GESTIONE TIMER
    virtual void removeTimer(Time) = 0;
    virtual void setTimerOn(Time, Time) = 0;
    virtual void setTimerOff(Time, Time) = 0;
};

#endif
