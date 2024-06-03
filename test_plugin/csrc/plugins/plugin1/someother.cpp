// someother.cpp
#include "someother.h"
#include <iostream>
#include <string>

namespace someother {
    void do_something(std::string s) {
        std::cout << s << " Plugin1 did some thing" << std::endl;
    }
}

// implementation of do_something()