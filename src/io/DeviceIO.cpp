#include "io/DeviceIO.hpp"

#include <fcntl.h>
#include <unistd.h>

Buffer
DeviceIO::read(
    const std::string& device,
    uint64_t offset,
    size_t bytes)
{
    Buffer buffer(bytes);

    int fd =
        open(device.c_str(), O_RDONLY);

    if(fd < 0)
    {
        return Buffer();
    }

    lseek(fd, offset, SEEK_SET);

    ::read(
        fd,
        buffer.data.data(),
        bytes);

    close(fd);

    return buffer;
}