#ifndef SAFETY_CHECKER_HPP
#define SAFETY_CHECKER_HPP

#include "device/Device.hpp"
#include "safety/SafetyResult.hpp"

class SafetyChecker
{
public:

    SafetyResult check(
        const Device& device);

private:

    bool isRootUser() const;

    bool isLoopDevice(
        const Device& device) const;

    bool isRamDevice(
        const Device& device) const;

    bool isMounted(
        const Device& device) const;

    bool isRootFilesystem(
        const Device& device) const;
};

#endif