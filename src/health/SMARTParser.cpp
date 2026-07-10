#include "health/SMARTParser.hpp"

#include <sstream>

SMARTInfo SMARTParser::parse(
    const std::string& output)
{
    SMARTInfo info;

    std::stringstream stream(output);

    std::string line;

    while(std::getline(stream,line))
    {
        if(line.find("temperature") != std::string::npos)
        {
            std::stringstream s(line);

            std::string temp;

            while(s >> temp)
            {
                if(std::isdigit(temp[0]))
                {
                    info.temperature =
                        std::stoi(temp);

                    break;
                }
            }
        }

        else if(line.find("percentage_used") != std::string::npos)
        {
            std::stringstream s(line);

            std::string value;

            while(s >> value)
            {
                if(std::isdigit(value[0]))
                {
                    info.percentageUsed =
                        std::stoi(value);

                    break;
                }
            }
        }

        else if(line.find("available_spare") != std::string::npos)
        {
            std::stringstream s(line);

            std::string value;

            while(s >> value)
            {
                if(std::isdigit(value[0]))
                {
                    info.availableSpare =
                        std::stoi(value);

                    break;
                }
            }
        }

        else if(line.find("power_cycles") != std::string::npos)
        {
            std::stringstream s(line);

            std::string value;

            while(s >> value)
            {
                if(std::isdigit(value[0]))
                {
                    info.powerCycles =
                        std::stoi(value);

                    break;
                }
            }
        }

        else if(line.find("power_on_hours") != std::string::npos)
        {
            std::stringstream s(line);

            std::string value;

            while(s >> value)
            {
                if(std::isdigit(value[0]))
                {
                    info.powerOnHours =
                        std::stoi(value);

                    break;
                }
            }
        }

        else if(line.find("unsafe_shutdowns") != std::string::npos)
        {
            std::stringstream s(line);

            std::string value;

            while(s >> value)
            {
                if(std::isdigit(value[0]))
                {
                    info.unsafeShutdowns =
                        std::stoi(value);

                    break;
                }
            }
        }

        else if(line.find("media_errors") != std::string::npos)
        {
            std::stringstream s(line);

            std::string value;

            while(s >> value)
            {
                if(std::isdigit(value[0]))
                {
                    info.mediaErrors =
                        std::stoi(value);

                    break;
                }
            }
        }
    }

    return info;
}