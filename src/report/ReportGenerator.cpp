#include "report/ReportGenerator.hpp"

#include <ctime>

Report
ReportGenerator::generate(
    const Device& device,
    const VerifyResult& verifyResult)
{
    Report report;

    report.deviceName =
        device.name;

    report.deviceModel =
        device.model;

    report.vendor =
        device.vendor;

    report.serialNumber =
        device.serial;

    report.capacity =
        static_cast<double>(device.capacity) /
        (1024.0 * 1024.0 * 1024.0);

    report.verificationSuccess =
        verifyResult.success;

    report.verificationPercent =
        verifyResult.verifiedPercent;

   report.eraseMethod =
    "Not Available";

report.eraseStatus =
    EraseStatus::NOT_STARTED;

    std::time_t now =
        std::time(nullptr);

    report.timestamp =
        std::ctime(&now);

    if(!report.timestamp.empty())
    {
        report.timestamp.pop_back();
    }

    return report;
}