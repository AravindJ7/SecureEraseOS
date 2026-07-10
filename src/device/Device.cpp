#include "device/Device.hpp"

#include <iostream>

Device::Device()
{
    type = DeviceType::UNKNOWN;

    capacity = 0;

    mounted = false;

    removable = false;
}

void Device::printInfo() const
{
    std::cout
        << "-----------------------------\n";

    std::cout
        << "Name : "
        << name
        << "\n";

    std::cout
        << "Path : "
        << path
        << "\n";

    std::cout
        << "Vendor : "
        << vendor
        << "\n";

    std::cout
        << "Model : "
        << model
        << "\n";

    std::cout
        << "Serial : "
        << serial
        << "\n";
}