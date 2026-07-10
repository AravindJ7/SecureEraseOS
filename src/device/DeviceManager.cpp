#include "device/DeviceManager.hpp"
#include "device/DeviceScanner.hpp"

std::vector<Device>
DeviceManager::scanDevices()
{
    DeviceScanner scanner;

    return scanner.scan();
}