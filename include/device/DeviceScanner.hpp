#ifndef DEVICE_SCANNER_HPP
#define DEVICE_SCANNER_HPP

#include <vector>

#include "device/Device.hpp"

class DeviceScanner
{
public:

    std::vector<Device> scan();
};

#endif