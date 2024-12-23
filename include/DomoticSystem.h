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
		Time currentTime;
		std::vector<std::string> logs;

	public:
		//GESTIONE DISPOSITIVI
		void addDevice(Device* device);
		Device* getDeviceByID(const std::string& id);

		//GESTIONE TEMPO
		void setTime(Time time);
		void resetTime();

		//DEBUG
		void resetTimers();
		void resetAll();

		//FUNZIONALITA'
		void logevent(const std::string& event);
		void handleOverload();

};



#endif /* DOMOTICSYSTEM_H_ */
