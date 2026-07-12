#ifndef SAFETY_RESULT_HPP
#define SAFETY_RESULT_HPP

#include <string>
#include <vector>

class SafetyResult
{
public:

    bool safe;

    std::vector<std::string> reasons;

public:

    SafetyResult();
};

#endif