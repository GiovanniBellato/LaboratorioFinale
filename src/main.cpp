#include <iostream>
#include "../include/Interface.h"

int main()
{
    Interface commandInterface;
    std::cout<<"Il programma e' pronto. Procedere inserendo i comandi: "<< std::endl;

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


    return 0;
}