#include "safety/SafetyChecker.hpp"

#include <unistd.h>

SafetyResult
SafetyChecker::check(
    const Device& device)
{
    SafetyResult result;

    if(!isRootUser())
    {
        result.safe = false;

        result.reasons.push_back(
            "Program is not running as root.");
    }

    if(isLoopDevice(device))
    {
        result.safe = false;

        result.reasons.push_back(
            "Loop devices cannot be erased.");
    }

    if(isRamDevice(device))
    {
        result.safe = false;

        result.reasons.push_back(
            "RAM disks cannot be erased.");
    }

    if(isMounted(device))
    {
        result.safe = false;

        result.reasons.push_back(
            "Device is currently mounted.");
    }

    if(isRootFilesystem(device))
    {
        result.safe = false;

        result.reasons.push_back(
            "Device contains the running operating system.");
    }

    return result;
}
bool SafetyChecker::isRootUser() const
{
    return geteuid() == 0;
}

bool SafetyChecker::isLoopDevice(
    const Device& device) const
{
    return device.name.rfind("loop",0)==0;
}

bool SafetyChecker::isRamDevice(
    const Device& device) const
{
    return device.name.rfind("ram",0)==0;
}

bool SafetyChecker::isMounted(
    const Device& device) const
{
    return device.mounted;
}

bool SafetyChecker::isRootFilesystem(
    const Device& device) const
{
    return device.mounted;
}