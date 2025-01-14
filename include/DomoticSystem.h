#ifndef DOMOTIC_SYSTEM_H
#define DOMOTIC_SYSTEM_H

#include <vector>
#include <memory> // Per smart pointers
#include <list>
#include "ManualDevice.h"
#include "CycleDevice.h"

class DomoticSystem {
private:
    std::vector<std::shared_ptr<Device>> devices; // Lista dei dispositivi
    std::list<std::shared_ptr<Device>> activeDevices; // Lista FIFO dei dispositivi accesi.
    //in quanto lista di gestione della policy di spegnimento in caso di eccesso della potenza limite,
    //essa non conterrà il fotovoltaico.
    const float maxPower = 3.5;    // Limite massimo di potenza dalla rete
    Time currentTime;  // Orario attuale del sistema
    Time fotovolt_on; //il fotovoltaico si accende alle 08:00
    Time fotovolt_off; //il fotovoltaico si spegne alle 18:00
    bool ignore_fotovolt; //il fotovoltaico può essere spento manualmente
    //durante il suo normale ciclo di funzionamento

    // Metodo per verificare la potenza totale assorbita
    float calculateTotalPower() const;

    // Metodo per gestire la policy di spegnimento in caso di superamento della potenza massima
    void enforcePowerLimit();

public:
    // Costruttore
    DomoticSystem(float maxPower);

    //Metodo per mostrare l'orario corrente
    void showTime();

    // Metodo per accendere un dispositivo
    void turnOnDevice(const std::string& deviceName);

    // Metodo per spegnere un dispositivo
    void turnOffDevice(const std::string& deviceName);

    // Metodo per impostare un timer per un dispositivo
    void setTimer(const std::string& deviceName, const Time& start, const Time& end);
    void setTimer(const std::string& deviceName, const Time& start);

    // Metodo per rimuovere il timer di un dispositivo
    void removeTimer(const std::string& deviceName);

    // Metodo per aggiornare lo stato dei dispositivi in base all'orario corrente
    void updateDevices();

    // Metodo per avanzare il tempo
    void setTime(Time& newTime);

    // Metodo per resettare il sistema
    void resetSystem();

    // Metodo per mostrare lo stato di tutti i dispositivi
    void showStatus();

    // Metodo per mostrare lo stato di un singolo dispositivo
    void showDeviceStatus(const std::string& deviceName);

    //Metodo per ritornare un vettore contenente il nome di tutti i dispositivi
    std::vector<std::string> getDevices();
};

#endif // DOMOTIC_SYSTEM_H
