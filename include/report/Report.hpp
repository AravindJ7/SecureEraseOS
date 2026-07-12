#ifndef REPORT_HPP
#define REPORT_HPP
#include "erase/EraseStatus.hpp"
#include <string>

class Report
{
public:

    std::string deviceName;

    std::string deviceModel;

    std::string serialNumber;

    std::string vendor;

    double capacity;

    std::string eraseMethod;

    EraseStatus eraseStatus;

    bool verificationSuccess;

    double verificationPercent;

    std::string timestamp;

public:

    Report();
};

#endif