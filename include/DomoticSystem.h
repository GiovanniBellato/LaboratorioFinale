#ifndef DOMOTICSYSTEM_H_
#define DOMOTICSYSTEM_H_

#include <vector>
#include <memory>
#include "Device.h"
#include "ManualDevice.h"
#include "Time.h"

class DomoticSystem {
private:
    std::vector<std::shared_ptr<Device>> devices; // Vettore di dispositivi
    Time currentTime; // Tempo attuale


public:
    // Aggiunge un dispositivo al sistema
    void addDevice(const std::shared_ptr<Device>& device) {
        devices.push_back(device);
    }

    // Rimuove un dispositivo dal sistema
    void removeDevice() {
        devices.erase(devices.begin());
    }
/*
    // Accende tutti i dispositivi
    void turnOnAllDevices() {
        for (auto& device : devices) {
            device->turnOn();
        }
    }

    // Spegne tutti i dispositivi
    void turnOffAllDevices() {
        for (auto& device : devices) {
            device->turnOff();
        }
    }

    // Imposta il timer di accensione su tutti i dispositivi
    void setTimerOnAllDevices(const Time& timer) {
        for (auto& device : devices) {
            device->setTimer(timer);
        }
    }

    // Rimuove il timer di accensione da tutti i dispositivi
    void removeTimerOnAllDevices() {
        for (auto& device : devices) {
            device->removeTimer();
        }
    }

    // Imposta l'ora attuale
    void setTime(const Time& time) {
        currentTime = time;
    }

    // Restituisce l'ora attuale
    Time getTime() const {
        return currentTime;
    }

    // Stampa lo stato di tutti i dispositivi
    void printDeviceStatus() const {
        for (const auto& device : devices) {
            device->printStatus();
        }
    }
    */
};
#endif // DOMOTICSYSTEM_H
