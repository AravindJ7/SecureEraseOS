#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <string>
#include <cstdint>

#include "device/DeviceType.hpp"

class Device
{
public:

    std::string name;
    std::string path;

    std::string vendor;
    std::string model;
    std::string serial;

    DeviceType type;

    uint64_t capacity;

    bool mounted;
    bool removable;

    Device();

    void printInfo() const;
};

#endif