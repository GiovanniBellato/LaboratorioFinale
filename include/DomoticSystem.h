#ifndef DOMOTICSYSTEM_H_
#define DOMOTICSYSTEM_H_

#include "Time.h"
#include "CycleDevice.h"
#include "ManualDevice.h"

#include <vector>
#include <string>

class DomoticSystem{
	private:

    //VARIABILI
		std::vector<Device*> devices;
		constexpr float MaxPower;
		float photovoltaicPower;
		int currentTime;
		std::vector<std::string> logs;

	public:
		//GESTIONE DISPOSITIVI
		void addDevice(Device* device);
		Device* getDeviceByName(const std::string& name);

		//GESTIONE TEMPO
		void setTime(int newTime);
		void resetTime();

		//DEBUG
		void resetTimers();
		void resetAll();

		//FUNZIONALITA'
		void logevent(const std::string& event);
		void handleOverload();

};



#endif /* DOMOTICSYSTEM_H_ */
