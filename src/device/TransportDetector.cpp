#include "device/TransportDetector.hpp"

#include <filesystem>

namespace fs = std::filesystem;

void TransportDetector::detect(Device& device)
{
    if(device.name.rfind("nvme",0)==0)
    {
        device.transport = TransportType::NVME;
        return;
    }

    std::string usb =
        "/sys/block/" +
        device.name +
        "/device";

    if(fs::exists(usb + "/../../usb"))
    {
        device.transport = TransportType::USB;
        return;
    }

    if(device.vendor == "Msft")
    {
        device.transport = TransportType::VIRTUAL;
        return;
    }

    device.transport = TransportType::SATA;
}