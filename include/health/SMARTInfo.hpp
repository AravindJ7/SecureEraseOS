#ifndef SMART_INFO_HPP
#define SMART_INFO_HPP

#include <string>

class SMARTInfo
{
public:

    int temperature;

    int percentageUsed;

    int availableSpare;

    int powerCycles;

    int powerOnHours;

    int unsafeShutdowns;

    int mediaErrors;

    std::string dataRead;

    std::string dataWritten;

    std::string health;

    SMARTInfo();
};

#endif