#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <string>
#include <vector>

#include "device/Device.hpp"
#include "erase/EraseStatus.hpp"

class Application
{
public:

    void run();

private:

    std::vector<Device> devices;

    Device selectedDevice;

    bool deviceSelected = false;
    EraseStatus lastEraseStatus =
        EraseStatus::NOT_STARTED;

    std::string lastEraseMethod =
        "Not Started";

    void initialize();

    void scanDevices();

    void selectDevice();

    void showMainMenu();

    void deviceInformation();

    void showDeviceHealth();

    void eraseDevice();

    void verifyErase();

    void generateReport();

    void changeDevice();

    void shutdown();
};

#endif