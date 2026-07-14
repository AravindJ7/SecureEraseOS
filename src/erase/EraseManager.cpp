#include "erase/EraseManager.hpp"

#include <chrono>
#include <iostream>
#include <thread>

#include "erase/EraseExecutor.hpp"
#include "erase/EraseMethod.hpp"
#include "executor/CommandResult.hpp"
#include "log/Logger.hpp"
#include "safety/SafetyChecker.hpp"
#include "safety/SafetyResult.hpp"
#include "ui/ProgressBar.hpp"

void EraseManager::start(const Device& device)
{
    status = EraseStatus::NOT_STARTED;
    method = "None";

    std::cout
        << "\n=================================\n";

    std::cout
        << " Secure Erase\n";

    std::cout
        << "=================================\n\n";

    std::cout
        << "Selected Device\n\n";

    std::cout
        << device.model
        << "\n";

    std::cout
        << device.path
        << "\n\n";

    SafetyChecker checker;

    SafetyResult safety =
        checker.check(device);

    if(!safety.safe)
    {
        std::cout
            << "\n=================================\n";

        std::cout
            << " Safety Check Failed\n";

        std::cout
            << "=================================\n\n";

        for(const auto& reason : safety.reasons)
        {
            std::cout
                << "- "
                << reason
                << "\n";
        }

        status = EraseStatus::FAILED;

        return;
    }

    EraseMethod eraseMethod =
        EraseMethod::NONE;

    if(device.type == DeviceType::NVME_SSD)
    {
        std::cout
            << "1. NVMe Sanitize\n";

        std::cout
            << "2. NVMe Format\n";

        std::cout
            << "3. Cancel\n\n";

        int choice;

        std::cout
            << "Choice : ";

        std::cin >> choice;

        if(choice == 1)
        {
            eraseMethod =
                EraseMethod::NVME_SANITIZE;

            method =
                "NVMe Sanitize";
        }
        else if(choice == 2)
        {
            eraseMethod =
                EraseMethod::NVME_FORMAT;

            method =
                "NVMe Format";
        }
        else
        {
            status =
                EraseStatus::CANCELLED;

            return;
        }
    }
    else if(
    device.type == DeviceType::HDD ||
    device.type == DeviceType::USB)
{
    std::cout
        << "1. Software Overwrite\n";

    std::cout
        << "2. Cancel\n\n";

    int choice;

    std::cout
        << "Choice : ";

    std::cin >> choice;

    if(choice == 1)
    {
        eraseMethod =
            EraseMethod::SOFTWARE_OVERWRITE;

        if(device.type == DeviceType::USB)
        {
            method =
                "USB Software Overwrite";
        }
        else
        {
            method =
                "Software Overwrite";
        }
    }
    else
    {
        status =
            EraseStatus::CANCELLED;

        return;
    }
}
    else
    {
        std::cout
            << "No erase method available.\n";

        status =
            EraseStatus::FAILED;

        return;
    }

    std::string confirm;

    std::cout
        << "\nWARNING!\n";

    std::cout
        << "All data will be destroyed.\n";

    std::cout
        << "Type YES to continue : ";

    std::cin >> confirm;

    if(confirm != "YES")
    {
        std::cout
            << "\nCancelled.\n";

        status =
            EraseStatus::CANCELLED;

        return;
    }

    EraseExecutor executor;

    CommandResult preview =
        executor.preview(
            device,
            eraseMethod);

    std::cout
        << "\n"
        << preview.output
        << "\n";

    std::cout
        << "\nPreview completed successfully.\n";

    std::cout
        << "\nExecute this command?\n\n";

    std::cout
        << "1. Yes\n";

    std::cout
        << "2. No\n\n";

    std::cout
        << "Choice : ";

    int executeChoice;

    std::cin >> executeChoice;

    if(executeChoice != 1)
    {
        status =
            EraseStatus::CANCELLED;

        std::cout
            << "\nOperation Cancelled.\n";

        return;
    }

    ProgressBar bar;

    for(int i = 0; i <= 100; i += 10)
    {
        bar.show(i);

        std::this_thread::sleep_for(
            std::chrono::milliseconds(200));
    }

    auto startTime =
        std::chrono::steady_clock::now();

    CommandResult execution =
        executor.execute(
            device,
            eraseMethod);

    auto endTime =
        std::chrono::steady_clock::now();

    auto seconds =
        std::chrono::duration_cast
        <
            std::chrono::seconds
        >(endTime - startTime);

    if(execution.success)
    {
        status =
            EraseStatus::SUCCESS;
    }
    else
    {
        status =
            EraseStatus::FAILED;
    }

    Logger logger;

    logger.write(
        "Device : " + device.path +
        "\nVendor : " + device.vendor +
        "\nModel : " + device.model +
        "\nMethod : " + method +
        "\nExit Code : " +
        std::to_string(execution.exitCode) +
        "\nExecution Time : " +
        std::to_string(seconds.count()) +
        " sec" +
        "\nStatus : " +
        (execution.success ? "SUCCESS" : "FAILED"));

    std::cout
        << "\n=================================\n";

    std::cout
        << " Execution Result\n";

    std::cout
        << "=================================\n\n";

    std::cout
        << execution.output
        << "\n";

    std::cout
        << "Exit Code : "
        << execution.exitCode
        << "\n";

    std::cout
        << "Execution Time : "
        << seconds.count()
        << " sec\n";

    std::cout
        << "Status : "
        << (execution.success ? "SUCCESS" : "FAILED")
        << "\n";
}

EraseStatus
EraseManager::getStatus() const
{
    return status;
}

std::string
EraseManager::getMethod() const
{
    return method;
}