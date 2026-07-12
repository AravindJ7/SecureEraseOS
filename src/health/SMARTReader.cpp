#include "health/SMARTReader.hpp"

#include <array>
#include <cstdio>

std::string
SMARTReader::read(
    const std::string& device)
{
    std::string command;

    // NVMe Device
    if(device.find("nvme") != std::string::npos)
    {
        command =
            "nvme smart-log " +
            device +
            " 2>/dev/null";
    }
    // SATA / HDD / USB
    else
    {
        command =
            "smartctl -a " +
            device +
            " 2>/dev/null";
    }

    std::array<char,256> buffer;

    std::string output;

    FILE* pipe =
        popen(command.c_str(),"r");

    if(pipe == nullptr)
    {
        return "";
    }

    while(fgets(buffer.data(),
                buffer.size(),
                pipe))
    {
        output += buffer.data();
    }

    pclose(pipe);

    return output;
}