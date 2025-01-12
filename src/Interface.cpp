#include "../include/Interface.h"
#include "../include/Time.h"
#include "../include/DomoticSystem.h"

#include <iostream>
#include <sstream>

//crea l'oggetto DomoticSystem
DomoticSystem sistemaDomotico(3);

//Metodo per l'elaborazione del comando da terminale passato come stringa
void Interface::commandReader(const std::string& command)
{
    //julio e' un oggetto di istringstream che estrae i dati uno a uno da command 
    std::istringstream julio(command); 
    
    std::string cmd, devicename, action, startTime, stopTime, time, word2, word3;
    
    //lettura della prima parola (in questo caso e' sempre un comando)
    julio >> cmd;


    if(cmd == "set")
    {
        //lettura della seconda parola
        julio >> word2;
        
        if(word2 == "time")
        {
            //lettura della terza parola (in questo caso un orario)
            julio >> time;
            Time targetTime = toTime(time);
            sistemaDomotico.setTime(targetTime);
        }
        else
        {
            //escluso si tratti di un comando set time, la seconda parola deve essere il nome del dispositivo su cui si vuole agire
            devicename = word2;

            //lettura della terza parola
            julio >> word3;

            if(word3 == "on" || word3 == "off")
            {
                action = word3;
                if(action == "on")
                {
                    sistemaDomotico.turnOnDevice(devicename);
                }
                else if(action == "off")
                {
                    sistemaDomotico.turnOffDevice(devicename);
                }
                else
                {
                    std::cerr<< "Il comando inserito non e' valido." << std::endl;
                }
            }
            else
            {
                startTime = word3;
                julio >> stopTime;
                sistemaDomotico.setTimer(devicename, toTime(startTime), toTime(stopTime));
            }
        }


    }
    else if (cmd == "rm")
    {
        julio >> devicename;
        //manca la funzione rm per togliere il timer 
        
    }
    else if (cmd == "show")
    {
        if(julio >> devicename)
        {
            //manca la funzione showDevice
            
        }
        else
        {
            //manca la funzione show
            
        }
    }
    else if (cmd == "reset")
    {
        julio >> word2;

        if(word2 == "time")
        {
            //manca la funzione resetTime
            
        }
        else if (word2 == "timers")
        {
            //manca la funzione resetTimers
           
        }
        else if (word2 == "all")
        {
            //manca la funzione resetAll
           
        }
        else
        {
            std::cerr<< "Il comando inserito non e' valido." << std::endl;
        }
    } 
    else
    {
        std::cerr<< "Il comando inserito non e' valido." << std::endl;
    }
}

Time toTime(std::string timeString)
{
    int hours = std::stoi(timeString.substr(0, 2));  // Estrai HH
    int minutes = std::stoi(timeString.substr(3, 2));  // Estrai MM

    Time temp(hours, minutes);
    return temp;
}
