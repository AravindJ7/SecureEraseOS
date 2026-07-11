#ifndef COMMAND_RESULT_HPP
#define COMMAND_RESULT_HPP

#include <string>

class CommandResult
{
public:

    bool success;

    int exitCode;

    std::string output;

    std::string error;

    CommandResult();
};

#endif