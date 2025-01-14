#include "../include/Interface.h"
#include "../include/Time.h"
#include "../include/DomoticSystem.h"

//CREO L'OGGETTO
DomoticSystem sistemaDomotico(3.5);

/* ATTENZIONE : SEPPUR INUTILE, IL COSTRUTTORE SEMBRA ESSERE RICHIESTO DA ALCUNI IDEE PER LA CORRETTA COMPILAZIONE */
Interface::Interface(){ /*NULLA*/ }

void Interface::commandReader(const std::string& command)
{
 
    //julio e' un oggetto di istringstream che estrae i dati uno a uno da command
    std::istringstream julio(command);

    std::vector<std::string> commandVector;
    std::string word;

    //VETTORE CHE CONTIENE UNA PAROLA DEL COMANDO FORNITO AD OGNI ELEMENTO
    while (julio >> word) 
     {
        commandVector.push_back(word);
    }

    //creo delle variabili per contenere i dati del comando
    std::string cmd, devicename, action, startTime, stopTime, time, word2, word3;

    //inizializzo le variabili a zero
    word2 = "0";
    word3 = "0";

    try{

    //controllo il primo elemento del vettore per capire quale comando è stato inserito
    if(commandVector[0] == "set")
    {
        //controllo il secondo elemento del vettore per capire quale comando è stato inserito
        if(commandVector[1] == "time")
        {
        	try{

                //LETTURA TERZA PAROLA ( IN QUESTO CASO UN ORARIO)
                time = commandVector[2];

                //CONTROLLO SE PER ERRORE SONO FINITE DELLE LETTERE NELL'ORARIO
                if(std::any_of(time.begin(), time.end(), ::isalpha))
                {
                    throw std::string("L'orario inserito non è valido.\n>");
                }
                Time targetTime = toTime(time);
                
                //imposto l'orario del sistema
                sistemaDomotico.setTime(targetTime);

        	}catch(...){
        		std::cerr<< "L'orario inserito non è valido." << std::endl << ">";
            }

        }
        else
        {
            //controllo se il comando è stato inserito correttamente
            try{
                if(commandVector[1] == "Impianto" || commandVector[1] =="impianto")
                {
                    if(commandVector[2] == "fotovoltaico" || commandVector[2] == "Fotovoltaico")
                    {
                        devicename = "Impianto fotovoltaico";
                        word2 = commandVector[3];
                        if(commandVector.size() == 5)
                        {
                            word3 = commandVector[4];
                        }
                    }
                }
                else if(commandVector[1] == "Lavatrice" || commandVector[1] =="lavatrice")
                {
                    devicename = "Lavatrice";
                    word2 = commandVector[2];
                    if(commandVector.size() == 4)
                        {
                            word3 = commandVector[3];
                        }
                }
                else if(commandVector[1] == "Lavastoviglie" || commandVector[1] =="lavastoviglie")
                {
                    devicename = "Lavastoviglie";
                    word2 = commandVector[2];
                    if(commandVector.size() == 4)
                        {
                            word3 = commandVector[3];
                        }
                }
                else if(commandVector[1] == "Pompa" || commandVector[1] =="pompa")
                {
                    if(commandVector[2] == "di" && (commandVector[3] == "calore" || commandVector[3] == "Calore") && commandVector[4] == "+" && (commandVector[5] == "termostato" || commandVector[5] == "Termostato"))
                    {
                        devicename = "Pompa di calore + termostato";
                        word2 = commandVector[6];
                        if(commandVector.size() == 8)
                        {
                            word3 = commandVector[7];
                        }
                    }
                }
                else if(commandVector[1] == "Tapparelle" || commandVector[1] =="tapparelle")
                {
                    if(commandVector[2] == "elettriche" || commandVector[2] == "Elettriche")
                    {
                        devicename = "Tapparelle elettriche";
                        word2 = commandVector[3];
                        if(commandVector.size() == 5)
                        {
                            word3 = commandVector[4];
                        }
                    }
                }
                else if(commandVector[1] == "Scaldabagno" || commandVector[1] =="scaldabagno")
                {
                    devicename = "Scaldabagno";
                    word2 = commandVector[2];
                    if(commandVector.size() == 4)
                        {
                            word3 = commandVector[3];
                        }
                }
                else if(commandVector[1] == "Frigorifero" || commandVector[1] =="frigorifero")
                {
                    devicename = "Frigorifero";
                    word2 = commandVector[2];
                    if(commandVector.size() == 4)
                        {
                            word3 = commandVector[3];
                        }
                }
                else if(commandVector[1] == "Forno" || commandVector[1] =="forno")
                {
                    if(commandVector[2] == "a" && (commandVector[3] == "microonde" || commandVector[3] == "Microonde"))
                    {
                        devicename = "Forno a microonde";
                        word2 = commandVector[4];
                        if(commandVector.size() == 6)
                        {
                            word3 = commandVector[5];
                        }
                    }
                }
                else if(commandVector[1] == "Asciugatrice" || commandVector[1] =="asciugatrice")
                {
                    devicename = "Asciugatrice";
                    word2 = commandVector[2];
                    if(commandVector.size() == 4)
                        {
                            word3 = commandVector[3];
                        }

                }
                else if(commandVector[1] == "Televisore" || commandVector[1] =="televisore")
                {
                    devicename = "Televisore";
                    word2 = commandVector[2];
                    if(commandVector.size() == 4)
                        {
                            word3 = commandVector[3];
                        }
                }
                else throw std::string("Errore, nel sistema non esiste un dispositivo con questo nome.\n>");
            }catch(...)
            {
                std::cerr<<"Errore, nel sistema non esiste un dispositivo con questo nome."<<std::endl <<">";
            }
            
            //controllo che la parola seguente sia "on" o "off" o un orario
            if(word2 == "on" || word2 == "off")
            {
                action = word2;
                
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
                stopTime="0"; //inizializzo a zero 
                startTime = word2;
                stopTime = word3;

                try{

                //controllo se ci sono delle lettere inserite per sbaglio nell'orario
                if(std::any_of(startTime.begin(), startTime.end(), ::isalpha))
                {
                    throw std::string("L'orario inserito non è valido.\n>");
                }
                

                Time start_t = toTime(startTime);

                if(stopTime != "0")
                {
                    if(sistemaDomotico.checkDevice(devicename) != 1) {
                        throw std::string("Non è possibile impostare un timer di spegnimento su un CycleDevice.\n>");
                    }else{

                    //controllo se ci sono delle lettere inserite per sbaglio nell'orario
                    if(std::any_of(stopTime.begin(), stopTime.end(), ::isalpha))
                    {
                        throw std::string("L'orario inserito non è valido.\n>");
                    }


                	Time stop_t = toTime(stopTime);
                	sistemaDomotico.setTimer(devicename, start_t, stop_t);
                    }
                }
                else sistemaDomotico.setTimer(devicename, start_t);
                }catch(...){
                	std::cerr<<"Orario inserito non valido"<<std::endl<<">";
                }
            }
        }
    }
    else if (commandVector[0] == "rm")
    {
        //controllo che esista il dispositivo e che lo spelling sia giusto
        try{
                if(commandVector[1] == "Impianto" || commandVector[1] =="impianto")
                {
                    if(commandVector[2] == "fotovoltaico")
                    {
                        devicename = "Impianto fotovoltaico";
                    }
                }
                else if(commandVector[1] == "Lavatrice" || commandVector[1] =="lavatrice")
                {
                    devicename = "Lavatrice";
                }
                else if(commandVector[1] == "Lavastoviglie" || commandVector[1] =="lavastoviglie")
                {
                    devicename = "Lavastoviglie";
                }
                else if(commandVector[1] == "Pompa" || commandVector[1] =="pompa")
                {
                    if(commandVector[2] == "di" && commandVector[3] == "calore" && commandVector[4] == "+" && commandVector[5] == "termostato")
                    {
                        devicename = "Pompa di calore + termostato";
                    }
                }
                else if(commandVector[1] == "Tapparelle" || commandVector[1] =="tapparelle")
                {
                    if(commandVector[2] == "elettriche")
                    {
                        devicename = "Tapparelle elettriche";
                    }
                }
                else if(commandVector[1] == "Scaldabagno" || commandVector[1] =="scaldabagno")
                {
                    devicename = "Scaldabagno";
                }
                else if(commandVector[1] == "Frigorifero" || commandVector[1] =="frigorifero")
                {
                    devicename = "Frigorifero";
                }
                else if(commandVector[1] == "Forno" || commandVector[1] =="forno")
                {
                    if(commandVector[2] == "a" && commandVector[3] == "microonde")
                    {
                        devicename = "Forno a microonde";
                    }
                }
                else if(commandVector[1] == "Asciugatrice" || commandVector[1] =="asciugatrice")
                {
                    devicename = "Asciugatrice";

                }
                else if(commandVector[1] == "Televisore" || commandVector[1] =="televisore")
                {
                    devicename = "Televisore";
                }
                else throw std::string("Errore, nel sistema non esiste un dispositivo con questo nome.\n>");
            }catch(...)
            {
                std::cerr<<"Errore, nel sistema non esiste un dispositivo con questo nome."<<std::endl<<">";
            }

        //rimuovo il timer del dispositivo
        sistemaDomotico.removeTimer(devicename);

    }
    else if (commandVector[0] == "show")
    {
        
        if(commandVector.size()>1)
        {
            //controllo che esista il dispositivo e che lo spelling sia giusto
            try{
                if(commandVector[1] == "Impianto" || commandVector[1] =="impianto")
                {
                    if(commandVector[2] == "fotovoltaico")
                    {
                        devicename = "Impianto fotovoltaico";
                    }
                }
                else if(commandVector[1] == "Lavatrice" || commandVector[1] =="lavatrice")
                {
                    devicename = "Lavatrice";
                }
                else if(commandVector[1] == "Lavastoviglie" || commandVector[1] =="lavastoviglie")
                {
                    devicename = "Lavastoviglie";
                }
                else if(commandVector[1] == "Pompa" || commandVector[1] =="pompa")
                {
                    if(commandVector[2] == "di" && commandVector[3] == "calore" && commandVector[4] == "+" && commandVector[5] == "termostato")
                    {
                        devicename = "Pompa di calore + termostato";
                    }
                }
                else if(commandVector[1] == "Tapparelle" || commandVector[1] =="tapparelle")
                {
                    if(commandVector[2] == "elettriche")
                    {
                        devicename = "Tapparelle elettriche";
                    }
                }
                else if(commandVector[1] == "Scaldabagno" || commandVector[1] =="scaldabagno")
                {
                    devicename = "Scaldabagno";
                }
                else if(commandVector[1] == "Frigorifero" || commandVector[1] =="frigorifero")
                {
                    devicename = "Frigorifero";
                }
                else if(commandVector[1] == "Forno" || commandVector[1] =="forno")
                {
                    if(commandVector[2] == "a" && commandVector[3] == "microonde")
                    {
                        devicename = "Forno a microonde";
                    }
                }
                else if(commandVector[1] == "Asciugatrice" || commandVector[1] =="asciugatrice")
                {
                    devicename = "Asciugatrice";

                }
                else if(commandVector[1] == "Televisore" || commandVector[1] =="televisore")
                {
                    devicename = "Televisore";
                }
                else throw std::string("Errore, nel sistema non esiste un dispositivo con questo nome.\n>");
            }catch(...)
            {
                std::cerr<<"Errore, nel sistema non esiste un dispositivo con questo nome."<<std::endl<<">";
            }

            //mostro lo stato del dispositivo
        	sistemaDomotico.showDeviceStatus(devicename);
        }
        else
        {
            //mostro lo stato di tutti i dispositivi
            sistemaDomotico.showStatus();

        }
    }
    else if (commandVector[0] == "reset")
    {

        if(commandVector[1] == "time")
        {
            //resetto l'orario del sistema
            sistemaDomotico.resetTime();
        }
        else if (commandVector[1] == "timers")
        {
            //rimuovo tutti i timer
            for(std::string nome : sistemaDomotico.getDevices())
            	sistemaDomotico.removeTimer(nome);
        }
        else if (commandVector[1] == "all")
        {
            //resetto il sistema
            sistemaDomotico.resetSystem();
        }
        else
        {
            throw std::string("Il comando inserito non e' valido.\n>");
        }
    }
    else
    {
    	throw std::string("Il comando inserito non e' valido.\n>");
    }
    
    }catch(...)
    {
    std::cerr<<"Il comando inserito non e' valido."<<std::endl<<">";
    }
}




