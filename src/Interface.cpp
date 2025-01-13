#include "../include/Interface.h"
#include "../include/Time.h"
#include "../include/DomoticSystem.h"

#include <iostream>
#include <sstream>

//crea l'oggetto DomoticSystem
DomoticSystem sistemaDomotico(3.5);

Interface::Interface(){
	//SONO INUTILE, CODICE SPRECATO.
}

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
        	try{
            //lettura della terza parola (in questo caso un orario)
            julio >> time;
            Time targetTime = toTime(time);
            sistemaDomotico.setTime(targetTime);
        	}catch(...){
        		throw std::string("L orario inserito non è valido.\n");
            }

        }
        else
        {
        	//CONTROLLO NOME DEVICE
        	for(std::string nome : sistemaDomotico.getDevices()){
        		if(devicename == nome) continue;
        		else {
        			throw std::string("Errore, il device inserito è sconosciuto\n");
        		}

        	}
            devicename = word2;

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
            }
            else
            {
                startTime = word3;

                try{
                Time start_t = toTime(startTime);

                if(julio >> stopTime){
                	Time stop_t = toTime(stopTime);
                	sistemaDomotico.setTimer(devicename, start_t, stop_t);
                		}
                else sistemaDomotico.setTimer(devicename, start_t);
                }catch(...){
                	throw std::string("Orario inserito non valido\n");
                }
            }
        }


    }
    else if (cmd == "rm")
    {
        julio >> devicename;
        //CONTROLLO NOME DEVICE
        for(std::string nome : sistemaDomotico.getDevices()){
                if(devicename == nome) continue;
                else {
                		throw std::string("Errore, il device inserito è sconosciuto\n");
                	}
        }
        sistemaDomotico.removeTimer(devicename);

    }
    else if (cmd == "show")
    {
        if(julio >> devicename)
        {
        	//CONTROLLO NOME DEVICE
        	for(std::string nome : sistemaDomotico.getDevices()){
        	        	if(devicename == nome) continue;
        	        	else {
        	        		throw std::string("Errore, il device inserito è sconosciuto\n");
        	        		}
        	    }
        	sistemaDomotico.showDeviceStatus(devicename);
        }
        else
        {
            sistemaDomotico.showStatus();

        }
    }
    else if (cmd == "reset")
    {
        julio >> word2;

        if(word2 == "time")
        {
            //TODO:RESET TIME

        }
        else if (word2 == "timers")
        {
            for(std::string nome : sistemaDomotico.getDevices())
            	sistemaDomotico.removeTimer(nome);

        }
        else if (word2 == "all")
        {
            sistemaDomotico.resetSystem();

        }
        else
        {
            throw std::string("Il comando inserito non e' valido.\n");
        }
    }
    else
    {
    	throw std::string("Il comando inserito non e' valido.\n");
    }
}



