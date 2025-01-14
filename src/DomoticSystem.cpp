#include "../include/DomoticSystem.h"

// COSTRUTTORE
DomoticSystem::DomoticSystem(float maxPower)
    : maxPower(maxPower), currentTime(0, 0) {
	Time t1(8,0);
	fotovolt_on = t1;
	Time t2(18,0);
	fotovolt_off = t2;
	ignore_fotovolt = false;

    // INIZIALIZZAZIONE DISPOSITIVI (FORNITI DA TABELLA PDF DEL PROGETTO)
    devices.push_back(std::make_shared<ManualDevice>("Impianto fotovoltaico", 0, -1.5));

    //MANUAL
    devices.push_back(std::make_shared<ManualDevice>("Pompa di calore + termostato", 1, 2.0));
    devices.push_back(std::make_shared<ManualDevice>("Scaldabagno", 2, 1.0));
    devices.push_back(std::make_shared<ManualDevice>("Frigorifero", 3, 0.4));

    //CYCLE
    devices.push_back(std::make_shared<CycleDevice>("Lavatrice", 4, 2.0, Time(1, 50)));
    devices.push_back(std::make_shared<CycleDevice>("Lavastoviglie", 5, 1.5, Time(3, 15)));
    devices.push_back(std::make_shared<CycleDevice>("Tapparelle elettriche", 6, 0.3, Time(0, 1)));
    devices.push_back(std::make_shared<CycleDevice>("Forno a microonde", 7, 0.8, Time(0, 2)));
    devices.push_back(std::make_shared<CycleDevice>("Asciugatrice", 8, 0.5, Time(1, 0)));
    devices.push_back(std::make_shared<CycleDevice>("Televisore", 9, 0.2, Time(1, 0)));
}

void DomoticSystem::showTime(){
    print ("L’orario attuale è " + currentTime.toString() + "\n");
}

void DomoticSystem::turnOnDevice(const std::string& deviceName) {
    for (const std::shared_ptr<Device>& device : devices) {
        if (device->getName() == deviceName) {
            if(deviceName != "Impianto fotovoltaico"){
                activeDevices.push_back(device); // Aggiungi in coda alla lista
            }
            else if(currentTime < fotovolt_on || currentTime >= fotovolt_off){
                print ("L'impianto fotovoltaico non può lavorare in assenza di luce solare. \n");
                return;
            }
            device->turnOn(currentTime);
            enforcePowerLimit(); // Controlla i limiti di potenza
        }
    }
}

void DomoticSystem::turnOffDevice(const std::string& deviceName) {
    for (const std::shared_ptr<Device>& device : devices) {
        if (device->getName() == deviceName) {
            device->turnOff(currentTime);
            if(deviceName == "Impianto fotovoltaico"){
                ignore_fotovolt = true;
            }
            else{
                activeDevices.remove(device); // Rimuovi dalla lista
            }
        }
    }
}

void DomoticSystem::setTimer(const std::string& deviceName, const Time& start, const Time& end) {
    for (const std::shared_ptr<Device>& device : devices) {
        if (device->getName() == deviceName) {
            device->setTimerOn(currentTime, start);
            device->setTimerOff(currentTime, end);
        }
    }
}

// Imposta un timer per un dispositivo (solo accensione)
void DomoticSystem::setTimer(const std::string& deviceName, const Time& start) {
    for (const std::shared_ptr<Device>& device : devices) {
        if (device->getName() == deviceName) {
            device->setTimerOn(currentTime, start);
        }
    }
}

void DomoticSystem::removeTimer(const std::string& deviceName) {
    for (const std::shared_ptr<Device>& device : devices) {
        if (device->getName() == deviceName) {
            device->removeTimer(currentTime);
        }
    }
}

float DomoticSystem::calculateTotalPower() const {
    float totalPower = 0.0;
    for (const std::shared_ptr<Device>& device : activeDevices)
        totalPower += device->getPower();
    //Gestisco a parte il consumo (negativo del fotovoltaico)
    if(!ignore_fotovolt)
        totalPower += devices[0]->getPower();
    return totalPower;
}

void DomoticSystem::enforcePowerLimit() {
    while (calculateTotalPower() > maxPower && !activeDevices.empty()) {
        // Spegni l'ultimo dispositivo acceso
        std::shared_ptr<Device> lastDevice = activeDevices.back(); // Ultimo dispositivo in coda

        print ("[" + currentTime.toString() + "] " + "Il dispositivo '" + lastDevice->getName() + "' è stato spento per superamento del limite di potenza. \n");

        lastDevice->turnOff(currentTime);
        activeDevices.pop_back(); // Rimuovi l'ultimo dispositivo dalla lista
    }
}

void DomoticSystem::updateDevices() {
    // GESTISCO IL FOTOVOLTAICO IN BASE ALL' ORARIO
    if (currentTime >= fotovolt_on && !ignore_fotovolt && currentTime < fotovolt_off) {
        turnOnDevice("Impianto fotovoltaico");
    } else if(currentTime >= fotovolt_off) {
        turnOffDevice("Impianto fotovoltaico");
    }
    // ITERA SUI DISPOSITIVI, ESCLUDENDO IL PRIMO (FOTOVOLTAICO)
    for (std::size_t i = 1; i < devices.size(); i++) {
        const std::shared_ptr<Device>& device = devices[i];
        device->update(currentTime);
    }
}

void DomoticSystem::setTime(Time& newTime) {
    if (!(newTime > currentTime)) {
        print ("Errore: Il nuovo orario deve essere successivo all'orario corrente. \n");
        return;
    }
    Time minuto(0,1);
    while (currentTime < newTime) {
        currentTime = currentTime + minuto; // Avanza di 1 minuto
        updateDevices();
    }
    print ("[" + currentTime.toString() + "] L'orario attuale è " + currentTime.toString() + "\n");
}

void DomoticSystem::resetSystem() {
    currentTime = Time(0, 0);
    for (const std::shared_ptr<Device>& device : devices) {
        device->turnOff(currentTime);
        device->removeTimer(currentTime);
    }
    ignore_fotovolt = false;
    print ("[00:00] L'orario attuale è 00:00 \n");
}

void DomoticSystem::showStatus(){
    float totalProduction = 0.0;
    float totalConsumption = 0.0;

    for (const std::shared_ptr<Device>& device : devices) {
        if (device->getPower() < 0) {
            totalProduction -= device->getConsumption(currentTime);
        } else {
            totalConsumption += device->getConsumption(currentTime);
        }
    }

    print ("[" + currentTime.toString() + "] Attualmente il sistema ha prodotto " + floatString(totalProduction) + " kWh e consumato " + floatString(totalConsumption) + " kWh. Nello specifico: \n");

    for (const std::shared_ptr<Device>& device : devices)
        print ("- Il dispositivo " + device->getName() + " ha consumato " + floatString(device->getConsumption(currentTime)) + " kWh \n");
}

void DomoticSystem::showDeviceStatus(const std::string& deviceName){
    for (const std::shared_ptr<Device>& device : devices) {
        if (device->getName() == deviceName) {
            print ("[" + currentTime.toString() + "] Il dispositivo " + deviceName + " ha attualmente consumato " +floatString(device->getConsumption(currentTime)) + " kWh. \n");
            return;
        }
    }
    print ("Errore: Dispositivo '" + deviceName + "' non trovato. \n");
}

std::vector<std::string> DomoticSystem::getDevices() {
    std::vector<std::string> devicesList;
    for (const std::shared_ptr<Device>& device : devices)
        devicesList.push_back (device->getName());
    return devicesList;
}

int DomoticSystem::checkDevice(const std::string& deviceName){
	for (const std::shared_ptr<Device>& device : devices)
	        if(device->getName() == deviceName){
	        	if (std::dynamic_pointer_cast<ManualDevice>(device)) {
	        	        return 1;
	        	    } else if (std::dynamic_pointer_cast<CycleDevice>(device)) {
	        	        return 2;
	        	    }}
	return 0;
}

void DomoticSystem::resetTime(){
	    currentTime = Time(0, 0);
	    for (const std::shared_ptr<Device>& device : devices) {
	        device->turnOff(currentTime);
	    }
	    ignore_fotovolt = false;
	    for(int i=0; i<15; i++) print("               \n");
	    print ("[00:00] L'orario attuale è 00:00 \n");
}
