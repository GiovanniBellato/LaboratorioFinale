#ifndef MANUALDEVICE_H_
#define MANUALDEVICE_H_

#include "Device.h"

using namespace std;

class ManualDevice:public Device{
private:
    string name;    //nome del dispositivo.
    int id; //identificativo unico.
    float power;    //consumo (o produzione) energetico.
    bool isOn;  //stato del dispositivo.
    Time timer;   //orario di accensione/spegnimento.
    
    float energyConsumed;   //consumo energetico totale

public:
    virtual void turnOn();  //accende il dispositivo.
    virtual void turnOff(); //spegne il dispositivo.
    virtual void update(int currentTime);   //aggiorna lo stato del dispositivo.
    void updateEnergy(int minutesElapsed);   //aggiorna il consumo energetico accumulato da un dispositivo
    void setTimer(Time);
};

#endif

