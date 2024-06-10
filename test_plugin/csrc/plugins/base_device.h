#pragma once

#include <iostream>
#include <string>

class BaseDevice {
public:
    virtual void do_something(std::string s) = 0;
    virtual void do_something_inner() = 0;  
    virtual ~BaseDevice() = default;
};


// this is the interface for all the plugins and plugin builders have to derive this since it is virtual class