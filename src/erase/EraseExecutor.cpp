#include "erase/EraseExecutor.hpp"

std::string
EraseExecutor::buildCommand(
    const Device& device,
    EraseMethod method)
{
    switch(method)
    {
        case EraseMethod::NVME_SANITIZE:

            return "nvme sanitize " +
                   device.path +
                   " --sanact=start-block-erase";

        case EraseMethod::NVME_FORMAT:

            return "nvme format " +
                   device.path;

        case EraseMethod::ATA_SECURE_ERASE:

            return "hdparm --security-erase password " +
                   device.path;

        case EraseMethod::ATA_ENHANCED:

            return "hdparm --security-erase-enhanced password " +
                   device.path;

        case EraseMethod::SOFTWARE_OVERWRITE:

            return "shred -v -n 3 " +
                   device.path;

        default:

            return "";
    }
}