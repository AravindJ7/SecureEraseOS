#include "erase/EraseExecutor.hpp"

#include "config/Config.hpp"
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

            if(SIMULATION_MODE)
            {
                return
                    "echo \"[SIMULATION] nvme sanitize "
                    + device.path +
                    " --sanact=start-block-erase\"";
            }

            return
                "nvme sanitize " +
                device.path +
                " --sanact=start-block-erase";

        case EraseMethod::NVME_FORMAT:

            if(SIMULATION_MODE)
            {
                return
                    "echo \"[SIMULATION] nvme format "
                    + device.path +
                    "\"";
            }

            return
                "nvme format " +
                device.path;

        case EraseMethod::ATA_SECURE_ERASE:

            if(SIMULATION_MODE)
            {
                return
                    "echo \"[SIMULATION] hdparm --security-erase password "
                    + device.path +
                    "\"";
            }

            return
                "hdparm --user-master u --security-set-pass password " +
                device.path +
                " && hdparm --user-master u --security-erase password " +
                device.path;

        case EraseMethod::ATA_ENHANCED:

            if(SIMULATION_MODE)
            {
                return
                    "echo \"[SIMULATION] hdparm --security-erase-enhanced password "
                    + device.path +
                    "\"";
            }

            return
                "hdparm --user-master u --security-set-pass password " +
                device.path +
                " && hdparm --user-master u --security-erase-enhanced password " +
                device.path;

        case EraseMethod::SOFTWARE_OVERWRITE:

            if(SIMULATION_MODE)
            {
                return
                    "echo \"[SIMULATION] shred -v -n 3 "
                    + device.path +
                    "\"";
            }

            return
                "shred -v -n 3 " +
                device.path;

        default:

            if(SIMULATION_MODE)
            {
                return
                    "echo \"[SIMULATION] Unknown erase method.\"";
            }

            return "";
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