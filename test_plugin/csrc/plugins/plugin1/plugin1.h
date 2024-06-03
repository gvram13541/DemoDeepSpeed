// #pragma once

// #include <iostream>
// #include "someother.h" 

// #include "base_device.h"

// class Plugin1 : public BaseDevice {
// public:
//     void do_something() override {
//         nvme::do_something();
//     }
// };


#pragma once

#include <iostream>
#include <string>
#include "someother.h" 

#include "../base_device.h"

class Plugin1 : public BaseDevice {
public:
    void do_something(std::string s) override {
        // Call the do_something() function from the someother namespace
        someother::do_something(s);
    }
};

// implementation of plugin1
// do_something was implemented in somother.cpp 
// we implemented like this to demonstrate that changes in pylib folder in actual deepspeed is not necessary
