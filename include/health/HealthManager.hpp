#ifndef HEALTH_MANAGER_HPP
#define HEALTH_MANAGER_HPP

#include <string>

#include "health/SMARTInfo.hpp"

class HealthManager
{
public:

    SMARTInfo readHealth(
        const std::string& device);

};

#endif