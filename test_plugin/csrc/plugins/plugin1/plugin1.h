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
    void do_something_inner() override {
        std::cout << "Plugin1 Device doing something inner!" << std::endl;
    }
};

// implementation of plugin1
// do_something was implemented in somother.cpp 
// we implemented like this to demonstrate that changes in pylib folder in actual deepspeed is not necessary
