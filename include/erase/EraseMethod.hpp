#ifndef ERASE_METHOD_HPP
#define ERASE_METHOD_HPP

#include <string>

enum class EraseMethod
{
    NONE,

    NVME_SANITIZE,

    NVME_FORMAT,

    ATA_SECURE_ERASE,

    ATA_ENHANCED,

    SOFTWARE_OVERWRITE
};

std::string
eraseMethodToString(
    EraseMethod method);

#endif