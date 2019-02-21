#include <tinyfsm.hpp>
#include <iostream>

struct Off; // forward declaration


// ----------------------------------------------------------------------------
// 1. Event Declarations
//
struct Toggle : tinyfsm::Event {
public:
    Toggle() {
        cout << "定义切换事件" << endl;
    }
};


// ----------------------------------------------------------------------------
// 2. State Machine Base Class Declaration
//
struct Switch : tinyfsm::Fsm<Switch>
{
  virtual void react(Toggle const &) {
      cout << "状态基类，对切换事件响应" << endl;
  };

  // alternative: enforce handling of Toggle in all states (pure virtual)
  //virtual void react(Toggle const &) = 0;

  virtual void entry(void) {
      cout << "状态基类，进入某种状态" << endl;
  };  /* entry actions in some states */
  void         exit(void)  {
      cout << "状态基类，退出某种状态" << endl;
  };  /* no exit actions */

  // alternative: enforce entry actions in all states (pure virtual)
  //virtual void entry(void) = 0;
};


// ----------------------------------------------------------------------------
// 3. State Declarations
//
struct On : Switch
{
  void entry() override {
      cout << "状态子类，进入on状态" << endl;
      std::cout << "* Switch is ON" << std::endl;
  };
  void react(Toggle const &) override {
      cout << "状态子类，在on状态下响应切换事件" << endl;
      transit<Off>();
      cout << "状态子类，在on状态下，已响应" << endl;
  };
};

struct Off : Switch
{
  void entry() override {
      cout << "状态子类，进入off状态" << endl;
      std::cout << "* Switch is OFF" << std::endl;
  };
  void react(Toggle const &) override {
      cout << "状态子类，在off状态下响应切换事件" << endl;
      transit<On>();
      cout << "状态子类，在off状态下，已响应" << endl;
  };
};

FSM_INITIAL_STATE(Switch, Off)


// ----------------------------------------------------------------------------
// 4. State Machine List Declaration (dispatches events to multiple FSM's)
//
// In this example, we only have a single state machine, no need to use FsmList<>:
//using fsm_handle = tinyfsm::FsmList< Switch >;
using fsm_handle = Switch;


