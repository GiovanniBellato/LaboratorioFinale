#ifndef MANUALDEVICE_H_
#define MANUALDEVICE_H_

#include "Device.h"

using namespace std;

class ManualDevice:public Device{
private:
    string name;    //nome del dispositivo.
    int id; //identificativo unico.
    float power;    //consumo (o produzione) energetico.
    float total_power; //consumo totale energetico
    bool isOn;  //stato del dispositivo.
    Time timer_on;
    bool timer;
    Time timer_off;
    Time start;
    Time end;

public:
    ManualDevice(float devicePower);
    void turnOn(Time time);  //accende il dispositivo.
    void turnOff(Time time); //spegne il dispositivo.
    void update(Time current_time);   //aggiorna lo stato del dispositivo.
    void setTimerOn(Time time);
    void setTimerOff(Time time);
};

#endif
