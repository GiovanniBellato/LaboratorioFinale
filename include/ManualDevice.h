#ifndef MANUALDEVICE_H_
#define MANUALDEVICE_H_

#include "Device.h"

class ManualDevice:public Device{
private:
    std::string name;    //nome del dispositivo.
    int id; //identificativo unico.
    float power;    //consumo (o produzione) energetico.
    float total_power; //consumo totale energetico
    bool isOn = false;  //stato del dispositivo.
    Time timer_on;
    bool timer = false;
    Time timer_off;
    Time start;
    Time end;

public:
    ManualDevice(float devicePower);
    void turnOn(Time time);  //accende il dispositivo.
    void turnOff(Time time); //spegne il dispositivo.
    void update(Time current_time);   //aggiorna lo stato del dispositivo.
    void setTimerOn(Time, Time);
    void setTimerOff(Time, Time);
    void CancTimer(Time);
    void reset();
};

#endif
