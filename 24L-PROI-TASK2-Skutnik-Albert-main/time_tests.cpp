#include "Time.h"
#include <iostream>
#include <sstream>


int main()
{
    Time t;
    if (t.getSeconds() != 0 || t.getMinutes() != 0 || t.getHours() != 0)
        std::cerr << "Error in default ctor.\n";
    t.addHours(1);
    t.addMinutes(2);
    t.addSeconds(4);
    if (t.getSeconds() != 4 || t.getMinutes() != 2 || t.getHours() != 1)
        std::cerr << "Error in direct initialization ctor.\n";
    Time t2(1, 3, 5);
    Time t3;
    t3 = t + t2;
    if (t3.getSeconds() != 9 || t3.getMinutes() != 5 || t3.getHours() != 2)
        std::cerr << "Error in addition ctor.\n";
    std::cout<< t << std::endl;
    t = t + t2;
    if (t.getSeconds() != 9 || t.getMinutes() != 5 || t.getHours() != 2)
        std::cerr << "Error in addition to time object ctor.\n";
    std::cout << t << std::endl;
    std::string text = "1:20:30";
    std::istringstream iss(text);
    int hours, minutes, seconds;
    char delim1, delim2;
    if (iss >> hours >> delim1 >> minutes >> delim2 >> seconds)
    {
        if (delim1 == ':' && delim2 == ':' &&
            hours >= 0 && minutes >= 0 && seconds >= 0)
        {

            if (seconds != 30 || minutes != 20 || hours != 1)
            {
                std::cerr << "Error in addition to time object ctor.\n";
            }
            std::cout << "Parsed time: " << hours << ":" << minutes << ":" << seconds << std::endl;
        }
        else
        {
            std::cerr << "Invalid time format or values.\n";
        }
    }
    else
    {
        std::cerr << "Error parsing the time string.\n";
    }
    return 0;
}

