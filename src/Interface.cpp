#include "../include/Interface.h"

#include <iostream>
#include <sstream>

Interface::Interface()
{
    
}

void Interface::commandReader(const std::string& command)
{
    std::istringstream julio(command); //julio e' un oggetto di istringstream che estrae i dati uno a uno da command 
    std::string cmd, devicename, action, startTime, stopTime, time;
    
    std::string word2;
    std::string word3;

    julio >> cmd;


    if(cmd == "set")
    {
        julio >> word2;
        
        if(word2 == "time")
        {
            julio >> time;
            //manca la funzione setTime
            std::cout<< "setTime" << std::endl;
        }
        else
        {
            devicename = word2;

            julio >> word3;

            if(word3 == "on" || word3 == "off")
            {
                action = word3;
                //manca la funzione setDevice on e off
                std::cout<< "setDevice onoff " << std::endl;
            }
            else
            {
                startTime = word3;
                julio >> stopTime;
                //manca la funzione setDevice con accensione e spegnimento
                std::cout<< " setDevice time" << std::endl;
            }
        }


    }
    else if (cmd == "rm")
    {
        julio >> devicename;
        //manca la funzione rm per togliere il timer 
        std::cout<< " remove timer" << std::endl;
    }
    else if (cmd == "show")
    {
        if(julio >> devicename)
        {
            //manca la funzione showDevice
            std::cout<< "showDevice " << std::endl;
        }
        else
        {
            //manca la funzione show
            std::cout<< " show" << std::endl;
        }
    }
    else if (cmd == "reset")
    {
        julio >> word2;

        if(word2 == "time")
        {
            //manca la funzione resetTime
            std::cout<< "reset time " << std::endl;
        }
        else if (word2 == "timers")
        {
            //manca la funzione resetTimers
            std::cout<< "reset timers " << std::endl;
        }
        else if (word2 == "all")
        {
            //manca la funzione resetAll
            std::cout<< "resest all " << std::endl;
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
