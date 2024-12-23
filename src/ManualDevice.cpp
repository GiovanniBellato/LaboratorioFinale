#include "ManualDevice.h"

using namespace std;

/*
    string name;    //nome del dispositivo.
    int id; //identificativo unico.
    const float power;    //consumo (o produzione) energetico.
    float total_power; //consumo totale energetico
    bool isOn;  //stato del dispositivo.
    Time timer_on;   //orario di accensione/spegnimento.
    bool timer;
    Time timer_off;
 
    Time start; //orario di accensione
    Time end;   //orario di spegnimento
 */

ManualDevice::ManualDevice(float devicePower){
    power = devicePower;
}

void ManualDevice::turnOn(Time current_time){  //accende il dispositivo.
    start = current_time;
    isOn = true;
}

void ManualDevice::turnOff(Time current_time){ //spegne il dispositivo.
    end = current_time;
    Time delta = end - start;
    total_power += power * delta.toHour();
    isOn = false;
}

void ManualDevice::update(Time current_time){   //aggiorna lo stato del dispositivo.
    if(!timer)
        return;
    if(current_time >= timer_on)
        turnOn(timer_on);
    if(current_time >= timer_off){
        turnOn(timer_off);
        timer = false;
    }
}

void ManualDevice::setTimerOn(Time time){
    timer_on = time;
    timer = true;
}

void ManualDevice::setTimerOff(Time time){
    timer_off = time;
    timer = true;
}

