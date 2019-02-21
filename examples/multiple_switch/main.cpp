//
// Created by gjs on 19-2-21.
//

#include "multiple_switch.h"


int main()
{
    fsm_handle::start();

    while(1)
    {
        char c;
        std::cout << std::endl << "0,1,2=Toggle single, a=Toggle all, r=Restart, q=Quit ? ";
        std::cin >> c;
        switch(c) {
            case '0': ToggleSingle<0>(); break;
            case '1': ToggleSingle<1>(); break;
            case '2': ToggleSingle<2>(); break;
            case 'a':
                std::cout << "> Toggling all switches..." << std::endl;
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
