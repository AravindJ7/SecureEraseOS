#include "device/Device.hpp"
#include <iomanip>
#include <iostream>

Device::Device()
{
    type = DeviceType::UNKNOWN;
    transport = TransportType::UNKNOWN;
    capacity = 0;

    mounted = false;

    removable = false;
}

void Device::printInfo() const
{
    std::cout
        << "-----------------------------------\n";

    std::cout
        << "Name      : "
        << name
        << "\n";

    std::cout
        << "Path      : "
        << path
        << "\n";

    std::cout
        << "Vendor    : "
        << vendor
        << "\n";

    std::cout
        << "Model     : "
        << model
        << "\n";

    std::cout
        << "Serial    : "
        << serial
        << "\n";

    std::cout
        << "Type      : ";

    switch(type)
    {
        case DeviceType::NVME_SSD:
            std::cout << "NVMe SSD";
            break;

        case DeviceType::SATA_SSD:
            std::cout << "SATA SSD";
            break;

        case DeviceType::HDD:
            std::cout << "Hard Disk";
            break;

        case DeviceType::USB:
            std::cout << "USB Storage";
            break;

        default:
            std::cout << "Unknown";
    }
    std::cout << "\n";
    std::cout
    << "Transport : ";

switch(transport)
{
    case TransportType::NVME:
        std::cout << "NVMe";
        break;

    case TransportType::SATA:
        std::cout << "SATA";
        break;

    case TransportType::USB:
        std::cout << "USB";
        break;

    case TransportType::VIRTUAL:
        std::cout << "Virtual";
        break;

    default:
        std::cout << "Unknown";
}

std::cout << "\n";

    std::cout
        << "\n";

    std::cout
        << "Capacity  : ";

    if(capacity == 0)
    {
        std::cout << "Unknown";
    }
    else
    {
        std::cout
    << std::fixed
    << std::setprecision(2)
    << static_cast<double>(capacity) /
       (1024.0 * 1024.0 * 1024.0)
    << " GB";
    }

    std::cout
        << "\n";

    std::cout
        << "Mounted   : "
        << (mounted ? "Yes" : "No")
        << "\n";

    std::cout
        << "Removable : "
        << (removable ? "Yes" : "No")
        << "\n";
}