#include "core/Application.hpp"

#include <iostream>

void Application::run()
{
    initialize();

    std::cout
        << "\nApplication Started Successfully.\n";

    shutdown();
}

void Application::initialize()
{
    std::cout
        << "=================================\n";

    std::cout
        << " SecureEraseOS v0.1\n";

    std::cout
        << "=================================\n\n";

    std::cout
        << "Initializing...\n";
}

void Application::shutdown()
{
    std::cout
        << "\nApplication Closed.\n";
}