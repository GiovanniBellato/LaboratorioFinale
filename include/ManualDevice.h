#ifndef MANUALDEVICE_H_
#define MANUALDEVICE_H_

#include "Device.h"

class ManualDevice:public Device{
private:
    std::string name;
    int id; //IDENTIFICATIVO UNICO
    float power;    //CONSUMO (O PRODUZIONE) ENERGETICA IN KWH
    float total_power = 0; //CONSUMO TOTALE EFFETTUATO DAL DISPOSITIVO
    bool isOn = false;  //STATO DEL DISPOSITIVO
    bool started = false; //VARIABILE DI UTILITA'

    //VARIABILI PER LA GESTIONE DEI TIMER
    Time timer_on;
    bool timer = false;
    Time timer_off;
    Time start;
    Time end;

public:
    ManualDevice(const std::string& name, int id, float power)
            : name(name), id(id), power(power) {}

    void turnOn(Time time) override;  //ACCENDO
    void turnOff(Time time) override; //SPENGO
    void update(Time current_time) override;   //AGGIORNA IL DISPOSITIVO AL NUOVO 'TEMPO' DATO

    //FUNZIONI PER LA GESTIONE DEI TIMER
    void setTimerOn(Time, Time) override;
    void setTimerOff(Time, Time) override;
    void removeTimer(Time) override;
    void reset();

    //FUNZIONI 'GET' PER L'ACCESSO ALLE INFORMAZIONI DEL DEVICE
    std::string getName() const override {return name;}
    float getPower() override {return power;}
    float getConsumption(Time) override;
};

#endif
