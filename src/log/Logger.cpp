#include "log/Logger.hpp"

#include <fstream>
#include <ctime>

void Logger::write(
    const std::string& message)
{
    std::ofstream log(
        "secureerase.log",
        std::ios::app);

    std::time_t now =
        std::time(nullptr);

    log
        << "=================================\n";

    log
        << std::ctime(&now);

    log
        << message;

    log
        << "\n\n";
}