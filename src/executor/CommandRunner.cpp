#include "executor/CommandRunner.hpp"

#include <array>
#include <cstdio>
#include <sys/wait.h>

CommandResult
CommandRunner::run(
    const std::string& command,
    ExecutionMode mode)
{
    CommandResult result;

    if(command.empty())
    {
        result.error =
            "Command is empty.";

        return result;
    }

    std::array<char, 256> buffer;

    if(mode == ExecutionMode::PREVIEW)
    {
        result.success = true;

        result.exitCode = 0;

        result.error.clear();

        result.output =
            "=====================================\n"
            " Execution Preview\n"
            "=====================================\n\n"
            "Command\n\n" +
            command +
            "\n\nStatus : Preview Only\n"
            "Nothing has been executed.\n";

        return result;
    }

    FILE* pipe =
        popen(
            (command + " 2>&1").c_str(),
            "r");

    if(pipe == nullptr)
    {
        result.error =
            "Unable to execute command.";

        return result;
    }

    while(fgets(buffer.data(),
                buffer.size(),
                pipe))
    {
        result.output +=
            buffer.data();
    }

    int status =
        pclose(pipe);

    if(WIFEXITED(status))
    {
        result.exitCode =
            WEXITSTATUS(status);

        result.success =
            (result.exitCode == 0);
    }
    else
    {
        result.exitCode = -1;

        result.success = false;
    }

    if(!result.success && result.error.empty())
    {
        result.error =
            "Command execution failed.";
    }

    return result;
}