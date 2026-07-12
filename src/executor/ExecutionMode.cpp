CommandResult
EraseExecutor::execute(
    const Device& device,
    EraseMethod method)
{
    CommandRunner runner;

    std::string command =
        buildCommand(device, method);

    return runner.run(
        command,
        ExecutionMode::EXECUTE);
}   