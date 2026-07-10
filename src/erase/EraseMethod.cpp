#include "erase/EraseMethod.hpp"

std::string
eraseMethodToString(
    EraseMethod method)
{
    switch(method)
    {
        case EraseMethod::NVME_SANITIZE:
            return "NVMe Sanitize";

        case EraseMethod::NVME_FORMAT:
            return "NVMe Format";

        case EraseMethod::ATA_SECURE_ERASE:
            return "ATA Secure Erase";

        case EraseMethod::ATA_ENHANCED:
            return "ATA Enhanced Secure Erase";

        case EraseMethod::SOFTWARE_OVERWRITE:
            return "Software Overwrite";

        default:
            return "None";
    }
}