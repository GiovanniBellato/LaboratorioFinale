#include "../include/CycleDevice.h"

void CycleDevice::turnOn(Time current_time){  
    if(!isOn){
    	started = true;
        start = current_time;
        isOn = true;
        print ("[" + current_time.toString() + "] Il dispositivo <" + name + "> si è acceso. \n");
    }
}

void CycleDevice::turnOff(Time current_time){  
    if(isOn){
        isOn = false;
        Time delta = current_time - start;
        total_power += (power * delta.toHour());
        if(timer && current_time >= timer_on)
            timer = false;
        print ("[" + current_time.toString() + "] Il dispositivo <" + name + "> si è spento. \n");
    }
}

void CycleDevice::update(Time current_time){  
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
    print ("[" + current_time.toString() + "] Impostato un timer di accesione nel dispositivo <" + name + ">" + " alle <" + timer_on.toString() + "> \n");
}

void CycleDevice::reset(){
    timer = false;
    isOn = false;
    total_power=0;
}

void CycleDevice::removeTimer(Time current_time){
    timer = false;
    print ("[" + current_time.toString() + "] Rimosso il timer dal dispositivo <" + name + "> \n");
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

