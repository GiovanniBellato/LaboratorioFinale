#include "../include/DomoticSystem.h"

// Costruttore
DomoticSystem::DomoticSystem(float maxPower)
    : maxPower(maxPower), currentTime(0, 0) {
	Time t1(8,0);
	fotovolt_on = t1;
	Time t2(18,0);
	fotovolt_off = t2;
	ignore_fotovolt = false;
    // Inizializzazione dei dispositivi dalla tabella del PDF
    devices.push_back(std::make_shared<ManualDevice>("Impianto fotovoltaico", 0, -1.5));
    //Manual devices
    devices.push_back(std::make_shared<ManualDevice>("Pompa di calore + termostato", 1, 2.0));
    devices.push_back(std::make_shared<ManualDevice>("Scaldabagno", 2, 1.0));
    devices.push_back(std::make_shared<ManualDevice>("Frigorifero", 3, 0.4));
    //Cycle devices
    devices.push_back(std::make_shared<CycleDevice>("Lavatrice", 4, 2.0, Time(1, 50)));
    devices.push_back(std::make_shared<CycleDevice>("Lavastoviglie", 5, 1.5, Time(3, 15)));
    devices.push_back(std::make_shared<CycleDevice>("Tapparelle elettriche", 6, 0.3, Time(0, 1)));
    devices.push_back(std::make_shared<CycleDevice>("Forno a microonde", 7, 0.8, Time(0, 2)));
    devices.push_back(std::make_shared<CycleDevice>("Asciugatrice", 8, 0.5, Time(1, 0)));
    devices.push_back(std::make_shared<CycleDevice>("Televisore", 9, 0.2, Time(1, 0)));
}


//Stampa a video l'orario corrente
void DomoticSystem::showTime(){
    print ("L’orario attuale è " + currentTime.toString() + "\n");
}

// Accende un dispositivo
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

// Spegne un dispositivo
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

// Imposta un timer per un dispositivo (accensione e spegnimento)
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

// Rimuove un timer per un dispositivo
void DomoticSystem::removeTimer(const std::string& deviceName) {
    for (const std::shared_ptr<Device>& device : devices) {
        if (device->getName() == deviceName) {
            device->removeTimer(currentTime);
        }
    }
}

// Calcola il consumo totale di potenza
float DomoticSystem::calculateTotalPower() const {
    float totalPower = 0.0;
    for (const std::shared_ptr<Device>& device : activeDevices)
        totalPower += device->getPower();
    //Gestisco a parte il consumo (negativo del fotovoltaico)
    if(!ignore_fotovolt)
        totalPower += devices[0]->getPower();
    return totalPower;
}

// Gestisce il limite massimo di potenza
void DomoticSystem::enforcePowerLimit() {
    while (calculateTotalPower() > maxPower && !activeDevices.empty()) {
        // Spegni l'ultimo dispositivo acceso
        std::shared_ptr<Device> lastDevice = activeDevices.back(); // Ultimo dispositivo in coda
        
        print ("[" + currentTime.toString() + "] " + "Il dispositivo '" + lastDevice->getName() + "' è stato spento per superamento del limite di potenza. \n");
        
        lastDevice->turnOff(currentTime);
        activeDevices.pop_back(); // Rimuovi l'ultimo dispositivo dalla lista
    }
}

// Aggiorna lo stato dei dispositivi
void DomoticSystem::updateDevices() {
    // Gestisci l'impianto fotovoltaico in base all'orario
    if (currentTime >= fotovolt_on && !ignore_fotovolt && currentTime < fotovolt_off) {
        turnOnDevice("Impianto fotovoltaico");
    } else if(currentTime >= fotovolt_off) {
        turnOffDevice("Impianto fotovoltaico");
    }
    // Itera sui dispositivi, escludendo il primo (Impianto fotovoltaico)
    for (std::size_t i = 1; i < devices.size(); i++) {
        const std::shared_ptr<Device>& device = devices[i];
        device->update(currentTime);
    }
}

// Avanza il tempo
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

// Resetta il sistema
void DomoticSystem::resetSystem() {
    currentTime = Time(0, 0);
    for (const std::shared_ptr<Device>& device : devices) {
        device->turnOff(currentTime);
        device->removeTimer(currentTime);
    }
    ignore_fotovolt = false;
    print ("[00:00] L'orario attuale è 00:00 \n");
}

// Mostra lo stato di tutti i dispositivi
void DomoticSystem::showStatus(){
    std::ostringstream prod, cons;
    prod.precision(2); cons.precision(2);
    float totalProduction = 0.0;
    float totalConsumption = 0.0;

    for (const std::shared_ptr<Device>& device : devices) {
        if (device->getPower() < 0) {
            totalProduction -= device->getConsumption(currentTime);
        } else {
            totalConsumption += device->getConsumption(currentTime);
        }
        prod << totalProduction; std::string str1 = prod.str();
        cons << totalConsumption; std::string str2 = cons.str();
    }
    prod << totalProduction; std::string str1 = prod.str();
    cons << totalConsumption; std::string str2 = cons.str();
    print ("[" + currentTime.toString() + "] Attualmente il sistema ha prodotto " + str1 + " kWh e consumato " + str2 + " kWh. Nello specifico: \n");

    for (const std::shared_ptr<Device>& device : devices){
    	std::ostringstream get_cons;
    	get_cons.precision(2);
    	get_cons << device->getConsumption(currentTime);
    	std::string str3 = get_cons.str();

        print ("- Il dispositivo " + device->getName() + " ha consumato " + str3 + " kWh \n");
} }

// Mostra lo stato di un singolo dispositivo
void DomoticSystem::showDeviceStatus(const std::string& deviceName){
    for (const std::shared_ptr<Device>& device : devices) {
        if (device->getName() == deviceName) {
        	std::ostringstream get_cons;
        	get_cons.precision(2);
        	get_cons << device->getConsumption(currentTime);
        	std::string str4 = get_cons.str();
            print ("[" + currentTime.toString() + "] Il dispositivo " + deviceName + " ha attualmente consumato " + str4 + " kWh. \n");
            return;
        }
    }
    print ("Errore: Dispositivo '" + deviceName + "' non trovato. \n");
}

//Ritorna un vettore di string contenente i nomi dei devices.
//Elementi in posizione 0 - 3 : manual devices
//Elementi in posizione 4 - 9 : cycle devices
std::vector<std::string> DomoticSystem::getDevices() {
    std::vector<std::string> devicesList;
    for (const std::shared_ptr<Device>& device : devices)
        devicesList.push_back (device->getName());
    return devicesList;
}

//Controlla se il device è manual o cycle
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
