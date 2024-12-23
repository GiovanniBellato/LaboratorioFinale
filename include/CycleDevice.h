#ifndef CYCLEDEVICE_H_
#define CYCLEDEVICE_H_

using namespace std;

class CycleDevice:public Device{
private:
    string name;    //nome del dispositivo.
    int id; //identificativo unico.
    float power;    //consumo (o produzione) energetico.
    bool isOn;  //stato del dispositivo.
    optional<pair<int, int>> timer;   //orario di accensione/spegnimento.
    float energyConsumed;   //consumo energetico totale
    int cycleDuration;    //Durata del ciclo in minuti.

public:
    virtual void turnOn();  //accende il dispositivo.
    virtual void turnOff(); //spegne il dispositivo.
    virtual void update(int currentTime);   //aggiorna lo stato del dispositivo.
    void updateEnergy(int minutesElapsed);   //aggiorna il consumo energetico accumulato da un dispositivo
    void startCycle(int currentTime);    //Avvia il ciclo.
};

#endif

