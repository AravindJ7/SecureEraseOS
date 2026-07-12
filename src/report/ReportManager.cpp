#include "report/ReportManager.hpp"
#include <fstream>
#include <filesystem>
#include <iomanip>
#include <iostream>

#include "report/ReportGenerator.hpp"
#include "erase/EraseStatus.hpp"

void ReportManager::generate(
    const Device& device,
    const VerifyResult& verifyResult)
{
    ReportGenerator generator;

    Report report =
        generator.generate(
            device,
            verifyResult);
            std::filesystem::create_directories("../reports");

std::ofstream file(
    "../reports/report.txt");

if(file)
{
    file
        << "=================================\n";

    file
        << " SecureEraseOS Report\n";

    file
        << "=================================\n\n";

    file
        << "Device Name          : "
        << report.deviceName
        << "\n";

    file
        << "Vendor               : "
        << report.vendor
        << "\n";

    file
        << "Model                : "
        << report.deviceModel
        << "\n";

    file
        << "Serial               : "
        << report.serialNumber
        << "\n";

    file
        << "Capacity             : "
        << std::fixed
        << std::setprecision(2)
        << report.capacity
        << " GB\n";

    file
        << "Erase Method         : "
        << report.eraseMethod
        << "\n";

    file
        << "Erase Status         : ";

    switch(report.eraseStatus)
    {
        case EraseStatus::NOT_STARTED:
            file << "Not Started";
            break;

        case EraseStatus::SUCCESS:
            file << "Success";
            break;

        case EraseStatus::FAILED:
            file << "Failed";
            break;

        case EraseStatus::CANCELLED:
            file << "Cancelled";
            break;
    }

    file << "\n";

    file
        << "Verification         : "
        << (report.verificationSuccess ? "PASS" : "FAIL")
        << "\n";

    file
        << "Verified             : "
        << report.verificationPercent
        << "%\n";

    file
        << "Timestamp            : "
        << report.timestamp
        << "\n";
}

    std::cout
        << "\n=================================\n";

    std::cout
        << " SecureEraseOS Report\n";

    std::cout
        << "=================================\n\n";

    std::cout
        << "Device Name          : "
        << report.deviceName
        << "\n";

    std::cout
        << "Vendor               : "
        << report.vendor
        << "\n";

    std::cout
        << "Model                : "
        << report.deviceModel
        << "\n";

    std::cout
        << "Serial               : "
        << report.serialNumber
        << "\n";

    std::cout
        << "Capacity             : "
        << std::fixed
        << std::setprecision(2)
        << report.capacity
        << " GB\n";

    std::cout
        << "Erase Method         : "
        << report.eraseMethod
        << "\n";

    std::cout
        << "Erase Status         : ";

    switch(report.eraseStatus)
    {
        case EraseStatus::NOT_STARTED:
            std::cout << "Not Started";
            break;

        case EraseStatus::SUCCESS:
            std::cout << "Success";
            break;

        case EraseStatus::FAILED:
            std::cout << "Failed";
            break;

        case EraseStatus::CANCELLED:
            std::cout << "Cancelled";
            break;
    }

    std::cout << "\n";

    std::cout
        << "Verification         : "
        << (report.verificationSuccess ? "PASS" : "FAIL")
        << "\n";

    std::cout
        << "Verified             : "
        << report.verificationPercent
        << "%\n";

    std::cout
        << "Timestamp            : "
        << report.timestamp
        << "\n";
        std::cout
    << "\nReport saved to reports/report.txt\n";
}