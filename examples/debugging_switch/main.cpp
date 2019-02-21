//
// Created by gjs on 19-2-21.
//

#include "debugging_switch.h"


int main()
{
    Switch::start();

    while(1)
    {
        char c;
        std::cout << "* main()" << std::endl
                  << "  cur_counter   = " << Switch::current_state_ptr->counter  << std::endl
                  << "  on_counter    = " << Switch::state<On>().counter  << std::endl
                  << "  off_counter   = " << Switch::state<Off>().counter << std::endl;

        std::cout << std::endl << "t=Toggle, r=Restart, q=Quit ? ";
        std::cin >> c;
        switch(c) {
            case 't':
                Switch::dispatch(Toggle());
                break;
            case 'r':
                Switch::reset();
                Switch::start();
                break;
            case 'q':
                return 0;
            default:
                std::cout << "> Invalid input" << std::endl;
        };
    }
}
