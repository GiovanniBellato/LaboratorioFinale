#ifndef CYCLE_DEVICE_H
#define CYCLE_DEVICE_H

#include "Device.h"

class CycleDevice : public Device {
private:
    std::string name;    
    int id;   //IDENTIFICATIVO UNICO
    float power;    //CONSUMO (O PRODUZIONE) ENERGETICO
    bool isOn = false;  //STATO DEL DISPOSITIVO
    float total_power = 0;  //CONSUMO TOTALE EFFETTUATO

    //VARIABILI PER LA GESTIONE DEI TIMER & DURATA CICLO
    Time start;         
    Time duration;   
    Time timer_on;
    bool timer = false;
    bool started = false;

public:
    CycleDevice(const std::string& name, int id, float power, Time duration)
            : name(name), id(id), power(power), duration(duration) {}

    virtual ~CycleDevice() = default;

    void turnOn(Time current_time) override;  //ACCENDE
    void turnOff(Time current_time) override;  //SPEGNE
    void update(Time current_time) override;  // AGGIORNA IL DISPOSITIVO AL NUOVO 'TEMPO' DATO

    //FUNZIONI PER GESTIONE DEI TIMER
    void setTimerOn(Time current_time, Time time) override;
    void setTimerOff(Time start, Time end) override;
    void removeTimer(Time) override;
    void reset();

    //FUNZIONI GET PER LA RACCOLTA DI INFORMAZIONI SUL DEVICE
    std::string getName() const override {return name;}
    float getPower() override {return power;}
    float getConsumption(Time) override;
};

#endif
