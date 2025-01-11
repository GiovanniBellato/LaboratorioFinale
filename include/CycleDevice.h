#ifndef CYCLE_DEVICE_H
#define CYCLE_DEVICE_H

#include "Device.h"

using namespace std;

class CycleDevice : public Device {
private:
    string name;    //nome del dispositivo.
    int id; //identificativo unico.
    float power;    //consumo (o produzione) energetico.
    bool isOn = false;  //stato del dispositivo.
    Time start;         // Orario di accensione
    Time duration; // Durata prefissata del ciclo
    float total_power = 0;   // Consumo totale energetico
    Time timer_on;
    bool timer = false;

public:
    CycleDevice(float devicePower);
    void turnOn(Time current_time);  //accende il dispositivo.
    void update(Time current_time);  // Aggiorna lo stato del dispositivo
    void setTimerOn(Time time);
    void reset();
};

#endif
