// pyds_aio_trampoline.cpp
#include <pybind11/pybind11.h>
#include "trampoline.h"

namespace py = pybind11;

PYBIND11_MODULE(py_ds_trampoline, m) {
    // Expose the load_device function directly
    m.def("load_device", [](const std::string& device_type) {
        auto aio = std::make_shared<Trampoline>(device_type);
        aio->load_device(device_type);
    }, "Load Device");

    m.def("do_something", [](const std::string& device_type, const std::string& s) {
        auto aio = std::make_shared<Trampoline>(device_type);
        aio->do_something(s);
    }, "Do Something");

    // Expose the Trampoline class and its methods
    py::class_<Trampoline, std::shared_ptr<Trampoline>>(m, "Trampoline")
        .def(py::init<const std::string&>())
        .def("load_device", &Trampoline::load_device)
        .def("do_something", &Trampoline::do_something)
        .def("get_handle", &Trampoline::get_handle);

    // Expose the handle class to access do_something_inner
    py::class_<handle, std::shared_ptr<handle>>(m, "handle")
        .def("do_something_inner", &handle::do_something_inner);
}