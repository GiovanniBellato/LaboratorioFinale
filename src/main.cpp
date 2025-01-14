#include <iostream>
#include "../include/Interface.h"

int main()
{
	std::cout<<"**** WARNING : Nell'input degli orari è importante utilizzare il formato hh:mm **** \n"<<std::endl;
	Interface commandInterface;
<<<<<<< Updated upstream
    	std::cout<<"Il programma e' pronto. Procedere inserendo i comandi: \n"<< std::endl;
try{
    while(true)
    {
	std::cout<<">";    
        std::string inputUtente;
        std::getline(std::cin, inputUtente);

        if(inputUtente == "exit")
=======
    std::cout<<"Il programma e' pronto. Procedere inserendo i comandi: \n"<< std::endl;
    try{
        while(true)
>>>>>>> Stashed changes
        {
	        std::cout<<">>";    
            std::string inputUtente;
            std::getline(std::cin, inputUtente);

            if(inputUtente == "exit")
            {
                std::cout<< "Chiusura del programma. Arrivederci!\n" << std::endl;
                break;
            }
            commandInterface.commandReader(inputUtente);
        }
    }catch(...){ std::cerr<<"PROGRAMMA CRASHATO."<<std::endl; }
    return 0;
    
}
