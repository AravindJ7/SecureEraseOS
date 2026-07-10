#ifndef ERASE_EXECUTOR_HPP
#define ERASE_EXECUTOR_HPP

#include <string>

#include "device/Device.hpp"
#include "erase/EraseMethod.hpp"

class EraseExecutor
{
public:

    std::string
    buildCommand(
        const Device& device,
        EraseMethod method);

};

#endif