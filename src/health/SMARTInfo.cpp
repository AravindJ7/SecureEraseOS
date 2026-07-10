#include "health/SMARTInfo.hpp"

SMARTInfo::SMARTInfo()
{
    temperature = 0;

    percentageUsed = 0;

    availableSpare = 0; 

    powerCycles = 0;

    powerOnHours = 0;

    unsafeShutdowns = 0;

    mediaErrors = 0;

    health = "Unknown";
}