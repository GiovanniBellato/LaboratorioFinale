#include "../include/ManualDevice.h"

void ManualDevice::turnOn(Time current_time){  
    if(!isOn){
        started = true;
        start = current_time;
        isOn = true;
        print ("[" + current_time.toString() + "] Il dispositivo <" + name + "> si è acceso. \n");
    }
}

void ManualDevice::turnOff(Time current_time){ 
    if(isOn){
        end = current_time;
        Time delta = end - start;
        total_power += power * delta.toHour();
        isOn = false;
        timer = false;
        print ("[" + current_time.toString() + "] Il dispositivo <" + name + "> si è spento. \n");
    }
}

void ManualDevice::update(Time current_time){   
    if(!timer)
        return;
    if(current_time >= timer_on)
        turnOn(timer_on);
    if(current_time >= timer_off)
        turnOff(timer_off);
}

void ManualDevice::setTimerOn(Time current_time, Time time){
    if(current_time <= time){
        timer_on = time;
        Time t_off(23,59);
        timer_off = t_off;
        timer = true;
        print ("[" + current_time.toString() + "] Impostato un timer di accesione nel dispositivo <" + name + ">" + " alle <" + timer_on.toString() + "> \n");
    } else {print("WARNING: Timer di accensione già scaduto (prova con orario successivo) \n");}
}

void ManualDevice::setTimerOff(Time current_time, Time time){
    if(current_time <= time){
        timer_off = time;
        timer = true;
        print ("[" + current_time.toString() + "] Impostato un timer di spegnimento nel dispositivo <" + name + ">" + " alle <" + timer_off.toString() + "> \n");
    } else {print ("WARNING: Timer di spegnimento già scaduto (prova con orario successivo) \n");}
}

void ManualDevice::removeTimer(Time current_time){
    timer = false;
    print ("[" + current_time.toString() + "] Rimosso il timer dal dispositivo <" + name + "> \n");

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
