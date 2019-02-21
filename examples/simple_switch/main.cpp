//
// Created by gjs on 19-2-21.
//

#include "simple_switch.h"

int main()
{
    // instantiate events
    Toggle toggle;

    fsm_handle::start();

    while(1)
    {
        char c;
        std::cout << std::endl << "t=Toggle, q=Quit ? ";
        std::cin >> c;
        switch(c) {
            case 't':
                std::cout << "> Toggling switch..." << std::endl;
                fsm_handle::dispatch(toggle);
                // alternative: instantiating causes no overhead (empty declaration)
                //fsm_handle::dispatch(Toggle());
                break;
            case 'q':
                return 0;
            default:
                std::cout << "> Invalid input" << std::endl;
        };
    }
}
