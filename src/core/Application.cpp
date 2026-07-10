#include "core/Application.hpp"

#include <iostream>

#include "device/DeviceManager.hpp"

void Application::run()
{
    initialize();

    scanDevices();

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

void Application::shutdown()
{
    std::cout
        << "Application Finished.\n";
}