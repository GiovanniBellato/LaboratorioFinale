#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>

class Interface 
{
    public:
        Interface();
        void commandReader(const std::string& command); 
        /* IL COMMAND-READER E' LA FUNZIONE PER L'INTERPRETAZIONE DEI COMANDI IN INPUT,
           E PER IL COLLEGAMENTO DI ESSI ALLE FUNZIONI DI DOMOTICSYSTEM.    */
};

#endif 
