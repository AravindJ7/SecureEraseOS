#ifndef DEVICE_IO_HPP
#define DEVICE_IO_HPP

#include <string>

#include "io/Buffer.hpp"

class DeviceIO
{
public:

    Buffer read(
        const std::string& device,
        uint64_t offset,
        size_t bytes);
};

#endif