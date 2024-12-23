#ifndef DEVICE_H_
#define DEVICE_H_

#include "Time.h"

#include <string>

using namespace std;

class Device{
private:
    string name;    //nome del dispositivo.
    int id; //identificativo unico.
    float power;    //consumo (o produzione) energetico.
    float total_power; //consumo totale energetico
    bool isOn;  //stato del dispositivo.
    Time timer_on;   //orario di accensione.
    bool timer = false;
    float energyConsumed;   //consumo energetico totale

protected:
    virtual void turnOn() = 0;  //accende il dispositivo.
    virtual void turnOff() = 0; //spegne il dispositivo.
    virtual void update(Time currentTime) = 0;   //aggiorna lo stato del dispositivo.
};

#endif

