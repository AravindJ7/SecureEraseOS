#include "device/DeviceInfoReader.hpp"

#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

static std::string readFile(const std::string& path)
{
    std::ifstream file(path);

    if(!file)
        return "";

    std::string value;

    std::getline(file, value);

    return value;
}

static uint64_t readCapacity(const std::string& device)
{
    std::ifstream file(
        "/sys/block/" +
        device +
        "/size");

    if(!file)
        return 0;

    uint64_t sectors = 0;

    file >> sectors;

    return sectors * 512ULL;
}

static bool readRemovable(const std::string& device)
{
    std::ifstream file(
        "/sys/block/" +
        device +
        "/removable");

    if(!file)
        return false;

    int value = 0;

    file >> value;

    return value == 1;
}

static bool isMounted(const std::string& path)
{
    std::ifstream file("/proc/mounts");

    if(!file)
        return false;

    std::string line;

    while(std::getline(file, line))
    {
        if(line.find(path) != std::string::npos)
        {
            return true;
        }
    }

    return false;
}

void DeviceInfoReader::populate(Device& device)
{
    std::string sys =
        "/sys/block/" +
        device.name +
        "/device/";

    device.vendor =
        readFile(sys + "vendor");

    device.model =
        readFile(sys + "model");

    device.serial =
        readFile(sys + "serial");

    device.capacity =
        readCapacity(device.name);

    device.removable =
        readRemovable(device.name);

    device.mounted =
        isMounted(device.path);
}