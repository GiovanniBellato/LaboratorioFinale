#include "../include/ManualDevice.h"
#include <iostream>

/*

    string name;    //nome del dispositivo.
    int id; //identificativo unico.
    float power;    //consumo (o produzione) energetico.
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
    if(!isOn){
    start = current_time;
    isOn = true;
    std::cout << "[";
    current_time.display();
    std::cout << "] Il dispositivo <" << name << "> si è acceso.";
    }
}

void ManualDevice::turnOff(Time current_time){ //spegne il dispositivo.
	if(isOn){
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

void ManualDevice::setTimerOn(Time curr_time, Time time){
	if(curr_time <= time){
    timer_on = time;
    timer = true;
    std::cout << "[";
    	curr_time.display();
    	std::cout<< "] Impostato un timer di accesione nel dispositivo <" << name << ">"<<" alle <";
    	time.display();
    	std::cout << ">";
	}else{
		std::cout<< "WARNING: Timer di accensione già scaduto (prova con orario successivo)";
	}
}

void ManualDevice::setTimerOff(Time curr_time, Time time){
	if(curr_time <= time){
    timer_off = time;
    timer = true;
    std::cout << "[";
        	curr_time.display();
        	std::cout<< "] Impostato un timer di spegnimento nel dispositivo <" << name << ">"<<" alle <";
        	time.display();
        	std::cout << ">";
	}else{
		std::cout<< "WARNING: Timer di spegnimento già scaduto (prova con orario successivo)";
	}
}

void ManualDevice::CancTimer(Time time){
	timer = false;
	std::cout << "[";
	time.display();
	std::cout<< "] Rimosso il timer dal dispositivo <" << name << ">" ;

}

void ManualDevice::reset(){
	timer = false;
	isOn = false;
	total_power=0;
}
