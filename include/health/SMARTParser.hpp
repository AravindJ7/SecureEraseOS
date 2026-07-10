#ifndef SMART_PARSER_HPP
#define SMART_PARSER_HPP

#include <string>

#include "health/SMARTInfo.hpp"

class SMARTParser
{
public:

    SMARTInfo parse(
        const std::string& output);

};

#endif