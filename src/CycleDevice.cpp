#include "../include/CycleDevice.h"
#include <iostream>

/*
 string name;    //nome del dispositivo.
 int id; //identificativo unico.
 float power;    //consumo (o produzione) energetico.
 bool isOn = false;  //stato del dispositivo.
 Time start;         // Orario di accensione
 Time duration; // Durata prefissata del ciclo
 float total_power = 0;   // Consumo totale energetico
 Time timer_on;
 bool timer = false;
 */

void CycleDevice::turnOn(Time current_time){  //accende il dispositivo.
    if(!isOn){
    	started = true;
        start = current_time;
        isOn = true;
        std::cout << "[" << current_time.toString() << "] Il dispositivo <" << name << "> si è acceso. \n";
    }
}

void CycleDevice::turnOff(Time current_time){  //spegne il dispositivo.
    if(isOn){
        isOn = false;
        Time delta = current_time - start;
        total_power += (power * delta.toHour());
        if(timer && current_time >= timer_on)
            timer = false;
        std::cout << "[" << current_time.toString() << "] Il dispositivo <" << name << "> si è spento. \n";
    }
}

void CycleDevice::update(Time current_time){  // Aggiorna lo stato del dispositivo
    if(timer && current_time >= timer_on)
        turnOn(timer_on);
    if(isOn)
        total_power += (power * duration.toHour());
    if(current_time >= start + duration)
        turnOff(start + duration);
}

void CycleDevice::setTimerOn(Time current_time, Time time){
    timer_on = time;
    timer = true;
    std::cout << "[" << current_time.toString() << "] Impostato un timer di accesione nel dispositivo <" << name << ">"<<" alle <" << current_time.toString() << "> \n";
}

void CycleDevice::reset(){
    timer = false;
    isOn = false;
    total_power=0;
}

void CycleDevice::removeTimer(Time current_time){
    timer = false;
    std::cout << "[" << current_time.toString() << "] Rimosso il timer dal dispositivo <" << name << "> \n" ;

}

void CycleDevice::setTimerOff(Time start, Time end) {}

float CycleDevice::getConsumption(Time current_time){
    if(started && isOn){
        Time delta = current_time - start;
        return (power * delta.toHour());
    }
    if(started)
        return (power * duration.toHour());
    return 0;
}

