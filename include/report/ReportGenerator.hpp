#ifndef REPORT_GENERATOR_HPP
#define REPORT_GENERATOR_HPP

#include "device/Device.hpp"
#include "verify/VerifyResult.hpp"
#include "report/Report.hpp"

class ReportGenerator
{
public:

    Report generate(
        const Device& device,
        const VerifyResult& verifyResult);
};

#endif