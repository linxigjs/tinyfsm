#include <tinyfsm.hpp>
#include <iostream>

// ----------------------------------------------------------------------------
// 1. Event Declarations
//
struct Toggle : tinyfsm::Event { };


// ----------------------------------------------------------------------------
// 2. State Machine Base Class Declaration
//
struct Switch : tinyfsm::MooreMachine<Switch>
{
/* pure virtual reaction (override required in all states) */
virtual void react(Toggle const &) = 0;
};


// ----------------------------------------------------------------------------
// 3. State Declarations
//
struct Off; // forward declaration

struct On : Switch
{
void entry() override {
    std::cout << "* Closing ciruit (light goes ON)" << std::endl;
};
void react(Toggle const &) override {
    transit<Off>();
};
};

struct Off : Switch
{
void entry() override {
    std::cout << "* Opening ciruit (light goes OFF)" << std::endl;
};
void react(Toggle const &) override {
    transit<On>();
};
};

FSM_INITIAL_STATE(Switch, Off)


