#include "../include/CycleDevice.h"
#include <iostream>

/*
 string name;    //nome del dispositivo.
 int id; //identificativo unico.
 const float power;    //consumo (o produzione) energetico.
 bool isOn = false;  //stato del dispositivo.
 Time start;         // Orario di accensione
 const Time duration; // Durata prefissata del ciclo
 float total_power = 0;   // Consumo totale energetico
 Time timer_on;
 bool timer = false;
 */

CycleDevice::CycleDevice(float devicePower){
    power = devicePower
}

void CycleDevice::turnOn(Time current_time){  //accende il dispositivo.
    if(!isOn){
        start = current_time;
        isOn = true;
        std::cout << "[";
        current_time.display();
        std::cout << "] Il dispositivo <" << name << "> si è acceso.";
    }
}

void CycleDevice::update(Time current_time){  // Aggiorna lo stato del dispositivo
    if(timer && current_time >= timer_on){
        isOn = true;
        start = timer_on;
        timer = false;
    }
    if(isOn){
        if(current_time >= start + duration){
            isOn = false;
            std::cout << "[";
            current_time.display();
            std::cout << "] Il dispositivo <" << name << "> si è spento.";
        }
        total_power += (power * duration.toHour());
    }
}

void CycleDevice::setTimerOn(Time time){
    timer_on = time;
    timer = true;
}

void CycleDevice::reset(){
    timer = false;
    isOn = false;
    total_power=0;
}

