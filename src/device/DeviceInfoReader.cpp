#include "device/DeviceInfoReader.hpp"

#include <fstream>
#include <filesystem>

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

void DeviceInfoReader::populate(Device& device)
{
    std::string sys =
        "/sys/block/" + device.name + "/device/";

    device.vendor =
        readFile(sys + "vendor");

    device.model =
        readFile(sys + "model");

    device.serial =
        readFile(sys + "serial");
}