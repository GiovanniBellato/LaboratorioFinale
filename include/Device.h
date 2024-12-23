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
    bool isOn;  //stato del dispositivo.
    Time timer;   //orario di accensione/spegnimento.
    float energyConsumed;   //consumo energetico totale

protected:
    virtual void turnOn();  //accende il dispositivo.
    virtual void turnOff(); //spegne il dispositivo.
    virtual void update(int currentTime);   //aggiorna lo stato del dispositivo.
    void updateEnergy(int minutesElapsed);   //aggiorna il consumo energetico accumulato da un dispositivo
};

#endif

