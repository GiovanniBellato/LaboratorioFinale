#include <string>

class Device{
private:
    std::string name;    //nome del dispositivo.
    int id; //identificativo unico.
    float power;    //consumo (o produzione) energetico.
    float total_power; //consumo totale energetico
    bool isOn;  //stato del dispositivo.
    Time timer_on;   //orario di accensione.
    bool timer = false;
    float energyConsumed;   //consumo energetico totale

public:

    Device() : timer_on(0, 0) {}
    virtual ~Device() = default;

    virtual void update(Time currentTime) = 0;   //aggiorna lo stato del dispositivo.
    virtual void turnOn(Time) = 0;  //accende il dispositivo.
    virtual void turnOff(Time) = 0; //spegne il dispositivo.
    virtual std::string getName() const = 0;
    virtual float getPower() = 0;
    virtual float getConsumption(Time) = 0;
    virtual void removeTimer(Time) = 0;
    virtual void setTimerOn(Time, Time) = 0;
    virtual void setTimerOff(Time, Time) = 0;
};

#endif
