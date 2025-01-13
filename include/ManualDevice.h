#ifndef MANUALDEVICE_H_
#define MANUALDEVICE_H_

#include "Device.h"
#include <string>

class ManualDevice:public Device{
private:
    std::string name;    //nome del dispositivo.
    int id; //identificativo unico.
    float power;    //consumo (o produzione) energetico.
    float total_power=0; //consumo totale energetico
    bool isOn = false;  //stato del dispositivo.
    Time timer_on;
    bool timer = false;
    Time timer_off;
    Time start;
    Time end;

public:
    ManualDevice(const std::string& name, int id, float power)
            : name(name), id(id), power(power) {}
    void turnOn(Time time) override;  //accende il dispositivo.
    void turnOff(Time time) override; //spegne il dispositivo.
    void update(Time current_time) override;   //aggiorna lo stato del dispositivo.
    void setTimerOn(Time, Time) override;
    void setTimerOff(Time, Time) override;
    void removeTimer(Time) override;
    void reset();
    std::string getName() const override {return name;}
    float getPower() override {return power;}
    float getConsumption(Time) override;
    bool started = false;

};

#endif
