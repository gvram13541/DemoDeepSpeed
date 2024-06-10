#pragma once

#include <string>
#include <memory>
#include <dlfcn.h>
#include <iostream>
#include "base_device.h"

class Trampoline;

class handle {
public:
    explicit handle(std::shared_ptr<Trampoline> trampoline) : trampoline_(trampoline) {}
    void do_something_inner();

private:
    std::shared_ptr<Trampoline> trampoline_;
};

class Trampoline : public std::enable_shared_from_this<Trampoline> {
public:
    explicit Trampoline(const std::string& device_type);
    void load_device(const std::string& device_type);
    void do_something(std::string s);
    std::shared_ptr<handle> get_handle();  // Method to get a handle instance

    ~Trampoline();

private:
    BaseDevice* device;
    void* handle_;
    friend class handle;  // Allow handle to access private members
};