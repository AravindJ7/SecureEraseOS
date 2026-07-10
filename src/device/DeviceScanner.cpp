#include "device/DeviceScanner.hpp"
#include "device/DeviceInfoReader.hpp"
#include <filesystem>

namespace fs = std::filesystem;

std::vector<Device>
DeviceScanner::scan()
{
    std::vector<Device> devices;
    DeviceInfoReader reader;
    for(const auto& entry :
        fs::directory_iterator("/sys/block"))
    {
        std::string name =
            entry.path().filename();

        // Ignore RAM disks
        if(name.rfind("ram", 0) == 0)
            continue;

        // Ignore loop devices
        if(name.rfind("loop", 0) == 0)
            continue;

        // Ignore CD/DVD drives
        if(name.rfind("sr", 0) == 0)
            continue;

        Device device;

        device.name = name;

        device.path =
            "/dev/" + name;
        reader.populate(device);
        devices.push_back(device);
    }

    return devices;
}