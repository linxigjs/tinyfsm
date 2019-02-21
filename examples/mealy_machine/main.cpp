//
// Created by gjs on 19-2-21.
//

#include "mealy_machine.h"


int main()
{
    Switch::start();

    std::cout << "> You are facing a light switch..." << std::endl;
    while(1)
    {
        char c;
        std::cout << std::endl << "t=Toggle, q=Quit ? ";
        std::cin >> c;
        switch(c) {
            case 't':
                std::cout << "> Toggling switch..." << std::endl;
                Switch::dispatch(Toggle());
                break;
            case 'q':
                return 0;
            default:
                std::cout << "> Invalid input" << std::endl;
        };
    }
}