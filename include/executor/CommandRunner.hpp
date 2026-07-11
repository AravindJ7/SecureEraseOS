#ifndef COMMAND_RUNNER_HPP
#define COMMAND_RUNNER_HPP

#include <string>
#include "executor/ExecutionMode.hpp"
#include "executor/CommandResult.hpp"

class CommandRunner
{
public:

    CommandResult run(
    const std::string& command,
    ExecutionMode mode);
};

#endif