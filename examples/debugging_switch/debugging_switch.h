#include <tinyfsm.hpp>
#include <cassert>


struct Off; // forward declaration


// ----------------------------------------------------------------------------
// Event Declarations
//
struct Toggle : tinyfsm::Event {
public:
    Toggle() {
        cout << "定义切换事件" << endl;
    }
}; // Event Declarations


// ----------------------------------------------------------------------------
// State Machine Declaration
//
struct Switch
        : tinyfsm::Fsm<Switch>
{
    static void reset(void);

    // NOTE: on reset: "tinyfsm::StateList<Off, On>::reset()", copy
    // constructor is used by default, so "this" points to neither
    // "Off" nor "On" (see operator=() below).
    Switch() : counter(0) {
      std::cout << "* Switch()" << std::endl
                << "  this          = " << this << std::endl;
    }

    ~Switch() {
      std::cout << "* ~Switch()" << std::endl
                << "  this          = " << this << std::endl;
    }

    Switch & operator=(const Switch & other) {
      std::cout << "* operator=()" << std::endl
                << "  this          = " << this << std::endl
                << "  other         = " << &other << std::endl;
      counter = other.counter;
      return *this;
    }

    virtual void react(Toggle const &) { };
    void entry(void);
    void exit(void);

    int counter;
};

struct On : Switch {
public:
    On() {
        cout << "状态on 构造函数" << endl;
    }
    void react(Toggle const &) override {
        cout << "状态on 对于toggle的响应" << endl;
        transit<Off>();
        cout << "状态on 对于toggle的响应结束" << endl;
    };
};

struct Off : Switch {
public:
    Off() {
        cout << "状态off 构造函数" << endl;
    }
    void react(Toggle const &) override {
        cout << "状态off 对于toggle的响应" << endl;
        transit<On>();
        cout << "状态off 对于toggle的响应结束" << endl;
    };
};

FSM_INITIAL_STATE(Switch, Off)


// ----------------------------------------------------------------------------
// State Machine Definitions
//
void Switch::reset() {
  tinyfsm::StateList<Off, On>::reset();
}

void Switch::entry() {
  counter++;

  // debugging only. properly designed state machines don't need this:
  if(is_in_state<On>())       {
      std::cout << "* On::entry()"  << std::endl;
  }
  else if(is_in_state<Off>()) {
      std::cout << "* Off::entry()" << std::endl;
  }
  else assert(true);

  assert(current_state_ptr == this);
  std::cout << "  this (cur)    = " << this << std::endl
            << "  state<On>     = " << &state<On>()  << std::endl
            << "  state<Off>    = " << &state<Off>() << std::endl;
}

void Switch::exit() {
  assert(current_state_ptr == this);
  std::cout << "* exit()" << std::endl
            << "  this (cur)    = " << this << std::endl
            << "  state<On>     = " << &state<On>()  << std::endl
            << "  state<Off>    = " << &state<Off>() << std::endl;
}


