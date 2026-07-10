#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <string>
#include <cstdint>

#include "device/DeviceType.hpp"
enum class TransportType
{
    NVME,
    SATA,
    USB,
    VIRTUAL,
    UNKNOWN
};

class Device
{
public:

    std::string name;
    std::string path;

    std::string vendor;
    std::string model;
    std::string serial;

    DeviceType type;    
    TransportType transport;

    uint64_t capacity;

    bool mounted;
    bool removable;

    Device();

    void printInfo() const;
};

#endif