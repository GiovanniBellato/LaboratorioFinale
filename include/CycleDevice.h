#ifndef CYCLE_DEVICE_H
#define CYCLE_DEVICE_H

#include "Device.h"
#include <string>

class CycleDevice : public Device {
private:
    std::string name;    //nome del dispositivo.
    int id; //identificativo unico.
    float power;    //consumo (o produzione) energetico.
    bool isOn = false;  //stato del dispositivo.
    Time start;         // Orario di accensione
    Time duration; // Durata prefissata del ciclo
    float total_power = 0;   // Consumo totale energetico
    Time timer_on;
    bool timer = false;
    bool started = false;

public:
    CycleDevice(const std::string& name, int id, float power, Time duration)
            : name(name), id(id), power(power), duration(duration) {}

    virtual ~CycleDevice() = default;

    void turnOn(Time current_time) override;  //accende il dispositivo.
    void turnOff(Time current_time) override;  //spegne il dispositivo.
    void update(Time current_time) override;  // Aggiorna lo stato del dispositivo
    void setTimerOn(Time current_time, Time time) override;
    void removeTimer(Time) override;
    void reset();
    std::string getName() const override {return name;}
    float getPower() override {return power;}
    float getConsumption(Time);

    void setTimerOff(Time start, Time end) override;
};

#endif
