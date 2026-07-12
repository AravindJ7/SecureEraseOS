#include "ui/ProgressBar.hpp"

#include <iostream>

void ProgressBar::show(int percent)
{
    const int width = 50;

    int filled =
        percent * width / 100;

    std::cout << "\r[";

    for(int i = 0; i < width; i++)
    {
        if(i < filled)
        {
            std::cout << "#";
        }
        else
        {
            std::cout << "-";
        }
    }

    std::cout
        << "] "
        << percent
        << "%";

    std::cout.flush();

    if(percent == 100)
    {
        std::cout << "\n";
    }
}