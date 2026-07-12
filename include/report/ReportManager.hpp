#ifndef REPORT_MANAGER_HPP
#define REPORT_MANAGER_HPP

#include "device/Device.hpp"
#include "verify/VerifyResult.hpp"

class ReportManager
{
public:

    void generate(
        const Device& device,
        const VerifyResult& verifyResult);
};

#endif