// trampoline.cpp
#include "trampoline.h"
#include <string>

void handle::do_something_inner() {
    if (trampoline_->device) {
        trampoline_->device->do_something_inner();
    } else {
        std::cerr << "No device loaded" << std::endl;
    }
}

Trampoline::Trampoline(const std::string& device_type) : device(nullptr), handle_(nullptr) {
    load_device(device_type);
}

void Trampoline::load_device(const std::string& device_type) {
    if (device) {
        delete device;
        device = nullptr;
    }
    if (handle_) {
        dlclose(handle_);
        handle_ = nullptr;
    }
    std::string lib_name = "lib" + device_type + "_device.so";
    handle_ = dlopen(lib_name.c_str(), RTLD_LAZY);
    if (!handle_) {
        std::cerr << "Cannot open library: " << dlerror() << '\n';
        return;
    }
    dlerror(); // Clear any existing error
    typedef BaseDevice* (*create_t)();
    create_t create_device = (create_t)dlsym(handle_, "create_device");
    const char* dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol create_device: " << dlsym_error << '\n';
        dlclose(handle_);
        handle_ = nullptr;
        return;
    }
    device = create_device();
}

void Trampoline::do_something(std::string s) {
    if (device) {
        device->do_something(s);  // Pass the string 's' here
    } else {
        std::cerr << "No device loaded" << std::endl;
    }
}

std::shared_ptr<handle> Trampoline::get_handle() {
    return std::make_shared<handle>(shared_from_this());
}

Trampoline::~Trampoline() {
    if (device) {
        delete device;
    }
    if (handle_) {
        dlclose(handle_);
    }
}