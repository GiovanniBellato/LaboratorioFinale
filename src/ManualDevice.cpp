#include "../include/ManualDevice.h"
#include <iostream>

/*

    string name;    //nome del dispositivo.
    int id; //identificativo unico.
    float power;    //consumo (o produzione) energetico.
    float total_power = 0; //consumo totale energetico
    bool isOn = false;  //stato del dispositivo.
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
    if(isOn != true){
    start = current_time;
    isOn = true;
    std::cout << "[";
    current_time.display();
    std::cout << "] Il dispositivo <" << name << "> si è acceso.";
    }
}

void ManualDevice::turnOff(Time current_time){ //spegne il dispositivo.
	if(isOn == true){
    end = current_time;
    Time delta = end - start;
    total_power += power * delta.toHour();
    isOn = false;
    	std::cout << "[";
        current_time.display();
        std::cout << "] Il dispositivo <" << name << "> si è spento.";
    timer = false;
	}
}

void ManualDevice::update(Time current_time){   //aggiorna lo stato del dispositivo.
    if(!timer)
        return;
    if(current_time >= timer_on)
        turnOn(timer_on);
    if(current_time >= timer_off){
        turnOff(timer_off);

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
