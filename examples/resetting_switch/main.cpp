//
// Created by gjs on 19-2-21.
//

#include "resetting_switch.h"


int main()
{
    fsm_handle::start();

    while(1)
    {
        char c;
        std::cout << std::endl << "t=Toggle, r=Restart, q=Quit ? ";
        std::cin >> c;
        switch(c) {
            case 't':
                std::cout << "> Toggling switch..." << std::endl;
                fsm_handle::dispatch(Toggle());
                break;
            case 'r':
                fsm_handle::reset();
                fsm_handle::start();
                break;
            case 'q':
                return 0;
            default:
                std::cout << "> Invalid input" << std::endl;
        };
    }
}
