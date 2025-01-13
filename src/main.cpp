#include <iostream>
#include "Interface.h"

int main()
{
	std::cout<<"----- Nell'input degli orari è importante utilizzare il formato hh:mm -----"<<std::endl;
	Interface commandInterface;
    	std::cout<<"Il programma e' pronto. Procedere inserendo i comandi: "<< std::endl;
try{
    while(true)
    {
        std::string inputUtente;
        std::getline(std::cin, inputUtente);

        if(inputUtente == "exit")
        {
            std::cout<< "Chiusura del programma. Arrivederci!" << std::endl;
            break;
        }
        commandInterface.commandReader(inputUtente);
    }
}catch(...){ throw std::string("PROGRAMMA CRASHATO."); }
    return 0;
    
}
