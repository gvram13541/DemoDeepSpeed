#pragma once

#include <string>
#include <memory>
#include <dlfcn.h>
#include <iostream>
#include <string>
#include "base_device.h"

// objective: this class has two pointers device and handle
// handle points to the so file of choosen device and device helps in pointing functionality of of device

class Trampoline {
public:
    explicit Trampoline(const std::string& device_type) : device(nullptr), handle(nullptr) {
        load_device(device_type);
    }

    void load_device(const std::string& device_type) {
        if (device) {
            delete device;
        }

        if (handle) {
            dlclose(handle);
        }

        std::string lib_name = "lib" + device_type + "_device.so";
        handle = dlopen(lib_name.c_str(), RTLD_LAZY);
        if (!handle) {
            std::cerr << "Cannot open library: " << dlerror() << '\n';
            return;
        }

        typedef BaseDevice* (*create_t)();
        create_t create_device = (create_t) dlsym(handle, "create_device");
        const char* dlsym_error = dlerror();
        if (dlsym_error) {
            std::cerr << "Cannot load symbol create_device: " << dlsym_error << '\n';
            dlclose(handle);
            handle = nullptr;
            return;
        }

        device = create_device();
    }

    void do_something(std::string s) {
        if (device) {
            device->do_something(s);
        } else {
            std::cerr << "No device loaded" << std::endl;
        }
    }

    ~Trampoline() {
        if (device) {
            delete device;
        }
        if (handle) {
            dlclose(handle);
        }
    }

private:
    BaseDevice* device;
    void* handle;
};
