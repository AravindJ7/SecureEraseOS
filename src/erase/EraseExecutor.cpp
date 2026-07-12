#include "erase/EraseExecutor.hpp"

#include "executor/CommandRunner.hpp"
#include "executor/ExecutionMode.hpp"

std::string
EraseExecutor::buildCommand(
    const Device& device,
    EraseMethod method)
{
    switch(method)
    {
        case EraseMethod::NVME_SANITIZE:

            return "echo \"[SIMULATION] NVMe Sanitize would execute on "
                   + device.path + "\"";

        case EraseMethod::NVME_FORMAT:

            return "echo \"[SIMULATION] NVMe Format would execute on "
                   + device.path + "\"";

        case EraseMethod::ATA_SECURE_ERASE:

            return "echo \"[SIMULATION] ATA Secure Erase would execute on "
                   + device.path + "\"";

        case EraseMethod::ATA_ENHANCED:

            return "echo \"[SIMULATION] ATA Enhanced Secure Erase would execute on "
                   + device.path + "\"";

        case EraseMethod::SOFTWARE_OVERWRITE:

            return "echo \"[SIMULATION] shred -v -n 3 "
                   + device.path +
                   "\"";

        default:

            return "echo \"[SIMULATION] Unknown erase method.\"";
    }
}

CommandResult
EraseExecutor::preview(
    const Device& device,
    EraseMethod method)
{
    std::string command =
        buildCommand(
            device,
            method);

    CommandRunner runner;

    return runner.run(
        command,
        ExecutionMode::PREVIEW);
}

CommandResult
EraseExecutor::execute(
    const Device& device,
    EraseMethod method)
{
    std::string command =
        buildCommand(
            device,
            method);

    CommandRunner runner;

    return runner.run(
        command,
        ExecutionMode::EXECUTE);
}