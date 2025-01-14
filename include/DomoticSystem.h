#ifndef DOMOTIC_SYSTEM_H
#define DOMOTIC_SYSTEM_H

#include <vector>
#include <memory> // PER UTILIZZO SMART POINTERS
#include <list>   // PER UTILIZZO LISTE
#include <iostream>
#include <sstream>

#include "ManualDevice.h"
#include "CycleDevice.h"

class DomoticSystem {
private:
    std::vector<std::shared_ptr<Device>> devices;   //LISTA DEI DEVICES
    std::list<std::shared_ptr<Device>> activeDevices;   //LISTA F.I.F.O. DEI DISPOSITIVI ACCESI
    /* ATTENZIONE : in quanto lista di gestione della policy di spegnimento in caso di eccesso della potenza limite,
    essa non conterrà il fotovoltaico. */

    const float maxPower = 3.5;    //LIMITE POTENZA DELLA RETE IN KWH
    Time currentTime;    //ORARIO DEL SISTEMA 

    Time fotovolt_on;   //ATTENZIONE : IL FOTOVOLTAICO SI ACCENDE AUTOMATICAMENTE ALLE 08:00
    Time fotovolt_off;   //ATTENZIONE : IL FOTOVOLTAICO SI SPEGNE AUTOMATICAMENTE ALLE 18:00 (PER MANCANZA DI LUCE)
    bool ignore_fotovolt; //ATTENZIONE : IL FOTOVOLTAICO PUO' ESSERE ACCESO/SPENTO A PIACIMENTO, MA SOLO NELL' ORARIO 08:00-18:00

    //FUNZIONI PER IL : CALCOLO DEL CONSUMO TOTALE - IL RISPETTO DEL LIMITE DI POTENZA DEL SISTEMA
    float calculateTotalPower() const;
    void enforcePowerLimit();

public:
    DomoticSystem(float maxPower);

    // MOSTRA ORARIO CORRENTE
    void showTime();

    // ACCENDI/SPEGNI DEVICE
    void turnOnDevice(const std::string& deviceName);
    void turnOffDevice(const std::string& deviceName);

    // IMPOSTA TIMER ACCENSIONE/SPEGNIMENTO, O RIMUOVILI ,DA UN DEVICE
    void setTimer(const std::string& deviceName, const Time& start, const Time& end);
    void setTimer(const std::string& deviceName, const Time& start);
    void removeTimer(const std::string& deviceName);

    // AGGIORNA I DEVICES ALL'ORARIO ATTUALE
    void updateDevices();

    // SETTING DELL'ORARIO ( ATTENZIONE: SI PUO' SOLO AVANZARE NEL TEMPO, CIO' AVVERRA' A SCATTI DI 1 MINUTO )
    void setTime(Time& newTime);

    // RESET SISTEMA O RESET TEMPORALE DI TUTTI I DEVICES (RESET DEI TIMER IMPLEMENTATO NELLA CLASSE DEI DEVICE)
    void resetSystem();
    void resetTime();

    // MOSTRA STATO DI UNO/TUTTI I DISPOSITIVI
    void showStatus();
    void showDeviceStatus(const std::string& deviceName);

    //RITORNA UN VETTORE CON I NOMI DI TUTTI I DISPOSITIVI NEL SISTEMA
    std::vector<std::string> getDevices();

    //CONTROLLO SE IL DISPOSITIVO E' CYCLE O MANUAL (UTILITA' PER INTERFACCIA)
    int checkDevice(const std::string&);
};

#endif // DOMOTIC_SYSTEM_H
