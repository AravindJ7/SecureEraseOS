#include "report/Report.hpp"
Report::Report()
{
    deviceName = "";

    deviceModel = "";

    serialNumber = "";

    vendor = "";

    capacity = 0.0;

    eraseMethod = "";

    eraseStatus = EraseStatus::NOT_STARTED;

    verificationSuccess = false;

    verificationPercent = 0.0;

    timestamp = "";
}