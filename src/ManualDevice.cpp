#include "../include/ManualDevice.h"
#include <iostream>

void ManualDevice::turnOn(Time current_time){  //accende il dispositivo.
    if(!isOn){
    started = true;
    start = current_time;
    isOn = true;
    std::cout << "[" << current_time.toString() << "] Il dispositivo <" << name << "> si è acceso." << std::endl;
    }
}

void ManualDevice::turnOff(Time current_time){ //spegne il dispositivo.
    if(isOn){
    end = current_time;
    Time delta = end - start;
    total_power += power * delta.toHour();
    isOn = false;
    timer = false;
    std::cout << "[" << current_time.toString() << "] Il dispositivo <" << name << "> si è spento." <<std::endl;
    }
}

void ManualDevice::update(Time current_time){   //aggiorna lo stato del dispositivo.
    if(!timer)
        return;
    if(current_time >= timer_on){
        turnOn(timer_on);
    }
    if(current_time >= timer_off){
        turnOff(timer_off);
    }
}

void ManualDevice::setTimerOn(Time current_time, Time time){
    if(current_time <= time){
    timer_on = time;
    Time t_off(23,59);
    timer_off = t_off;
    timer = true;
    std::cout << "[" << current_time.toString() << "] Impostato un timer di accesione nel dispositivo <" << name << ">"<<" alle <" << timer_on.toString() << ">" <<std::endl;
    }else{
        std::cout<< "WARNING: Timer di accensione già scaduto (prova con orario successivo)"<<std::endl;
    }
}

void ManualDevice::setTimerOff(Time current_time, Time time){
    if(current_time <= time){
        timer_off = time;
        timer = true;
        std::cout << "[" << current_time.toString() << "] Impostato un timer di spegnimento nel dispositivo <" << name << ">"<<" alle <" << timer_off.toString() << ">" << std::endl;
    }else{
        std::cout<< "WARNING: Timer di spegnimento già scaduto (prova con orario successivo)" <<std::endl;
    }
}

void ManualDevice::removeTimer(Time current_time){
    timer = false;
    std::cout << "[" << current_time.toString() << "] Rimosso il timer dal dispositivo <" << name << ">" <<std::endl ;

}

void ManualDevice::reset(){
    timer = false;
    isOn = false;
    total_power=0;
}

float ManualDevice::getConsumption(Time current_time){
	if(started && isOn){
        Time delta = current_time - start;
        return (power * delta.toHour());
	}
    if(started){
        Time delta = end - start;
        return (power * delta.toHour());
    }
	return 0;
}
