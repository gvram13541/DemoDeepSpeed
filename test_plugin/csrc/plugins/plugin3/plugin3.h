#pragma once

#include <iostream>
#include <string>
#include "../base_device.h"

class Plugin3 : public BaseDevice {
public:
    void do_something(std::string s) override {
        std::cout << "Plugin3 doing something" << std::endl;
    }
};
