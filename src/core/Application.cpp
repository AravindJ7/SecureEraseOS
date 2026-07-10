#include "core/Application.hpp"

#include <iostream>

#include "device/DeviceManager.hpp"
#include "health/HealthManager.hpp"

void Application::run()
{
    initialize();

    scanDevices();

    showDeviceHealth();

    shutdown();
}

void Application::initialize()
{
    std::cout
        << "=================================\n";

    std::cout
        << " SecureEraseOS v0.2\n";

    std::cout
        << "=================================\n\n";
}

void Application::scanDevices()
{
    std::cout
        << "Scanning storage devices...\n\n";

    DeviceManager manager;

    auto devices =
        manager.scanDevices();

    for(const auto& device : devices)
    {
        device.printInfo();

        std::cout << "\n";
    }
}

void Application::showDeviceHealth()
{
    std::cout
        << "=================================\n";

    std::cout
        << " Device Health\n";

    std::cout
        << "=================================\n\n";

    HealthManager manager;

    SMARTInfo info =
        manager.readHealth("/dev/nvme0");

    std::cout
        << "Temperature      : "
        << info.temperature
        << " C\n";

    std::cout
        << "Available Spare  : "
        << info.availableSpare
        << " %\n";

    std::cout
        << "Percentage Used  : "
        << info.percentageUsed
        << " %\n";

    std::cout
        << "Power Cycles     : "
        << info.powerCycles
        << "\n";

    std::cout
        << "Power On Hours   : "
        << info.powerOnHours
        << "\n";

    std::cout
        << "Unsafe Shutdowns : "
        << info.unsafeShutdowns
        << "\n";

    std::cout
        << "Media Errors     : "
        << info.mediaErrors
        << "\n\n";
}

void Application::shutdown()
{
    std::cout
        << "Application Finished.\n";
}