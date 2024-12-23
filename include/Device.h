#ifndef DEVICE_H_
#define DEVICE_H_

#include "CycleDevice.h"
#include "DomoticSystem.h"
#include "ManualDevice.h"

using namespace std;

class Device{
private:
    string name;    //nome del dispositivo.
    int id; //identificativo unico.
    float power;    //consumo (o produzione) energetico.
    bool isOn;  //stato del dispositivo.
    optional<pair<int, int>> timer;   //orario di accensione/spegnimento.
    float energyConsumed;   //consumo energetico totale

public:
    virtual void turnOn();  //accende il dispositivo.
    virtual void turnOff(); //spegne il dispositivo.
    virtual void update(int currentTime);   //aggiorna lo stato del dispositivo.
    void updateEnergy(int minutesElapsed);   //aggiorna il consumo energetico accumulato da un dispositivo
};

#endif

