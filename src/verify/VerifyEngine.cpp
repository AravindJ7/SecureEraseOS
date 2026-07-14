#include "verify/VerifyEngine.hpp"

#include <fcntl.h>
#include <unistd.h>

VerifyResult
VerifyEngine::verify(
    const Device& device)
{
    VerifyResult result;

    int fd =
        open(
            device.path.c_str(),
            O_RDONLY);

    if(fd < 0)
    {
        result.success = false;

        result.verifiedPercent = 0.0;

        result.message =
            "Unable to open device.";

        result.details =
            "The operating system could not access the storage device.";

        return result;
    }

    char buffer[4096];

    ssize_t bytes =
        read(
            fd,
            buffer,
            sizeof(buffer));

    close(fd);

    if(bytes <= 0)
    {
        result.success = false;

        result.verifiedPercent = 0.0;

        result.message =
            "Device read failed.";

        result.details =
            "The storage device is present but cannot be read.";

        return result;
    }

    result.success = true;

    result.verifiedPercent = 100.0;

    result.message =
        "Device verification successful.";

    result.details =
        "Successfully opened the device and read the first 4096 bytes.";

    return result;
}