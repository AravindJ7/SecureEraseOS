#include "health/HealthManager.hpp"

#include "health/SMARTReader.hpp"
#include "health/SMARTParser.hpp"

SMARTInfo HealthManager::readHealth(
    const std::string& device)
{
    SMARTReader reader;

    SMARTParser parser;

    std::string output =
        reader.read(device);

    return parser.parse(output);
}