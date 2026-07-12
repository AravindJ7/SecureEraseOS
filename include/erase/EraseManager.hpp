#ifndef ERASE_MANAGER_HPP
#define ERASE_MANAGER_HPP

#include <string>

#include "device/Device.hpp"
#include "erase/EraseStatus.hpp"

class EraseManager
{
public:

    void start(const Device& device);

    EraseStatus getStatus() const;

    std::string getMethod() const;

private:

    EraseStatus status =
        EraseStatus::NOT_STARTED;

    std::string method =
        "None";
};

#endif