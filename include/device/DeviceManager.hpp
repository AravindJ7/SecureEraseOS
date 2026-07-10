#ifndef DEVICE_MANAGER_HPP
#define DEVICE_MANAGER_HPP

#include <vector>

#include "device/Device.hpp"

class DeviceManager
{
public:

    std::vector<Device> scanDevices();
};

#endif