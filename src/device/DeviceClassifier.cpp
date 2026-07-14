#include "device/DeviceClassifier.hpp"

#include <fstream>

static std::string readFile(const std::string& path)
{
    std::ifstream file(path);

    if(!file)
        return "";

    std::string value;

    std::getline(file, value);

    return value;
}

void DeviceClassifier::classify(Device& device)
{
    if(device.name.rfind("nvme", 0) == 0)
    {
        device.type =
            DeviceType::NVME_SSD;

        return;
    }

    std::string rotational =
        readFile(
            "/sys/block/" +
            device.name +
            "/queue/rotational");

    std::string removable =
        readFile(
            "/sys/block/" +
            device.name +
            "/removable");

    if(device.name.rfind("sd",0) == 0)
    {
        if(removable == "1")
        {
            device.type =
                DeviceType::USB;

            return;
        }

        if(rotational == "0")
        {
            device.type =
                DeviceType::SATA_SSD;
        }
        else
        {
            device.type =
                DeviceType::HDD;
        }

        return;
    }

    device.type =
        DeviceType::UNKNOWN;
}