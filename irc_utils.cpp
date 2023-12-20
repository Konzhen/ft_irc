#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string.h>

bool check_ip(const char *ip);

bool check_ip(const char *ip)
{
    if (ip[strlen(ip) - 1] == '.')
        return (true);
    std::istringstream  stream(ip);
    std::string         str;
    int                 count = 0;

    while (std::getline(stream, str, '.'))
    {
        for (size_t i = 0; i < str.length(); i++)
        {
            if (!isdigit(str[i]))
                return (true);
        }
        if (std::atoi(str.c_str()) < 0 || std::atoi(str.c_str()) > 255)
            return (true);
        count++;
    }
    if (count != 4)
        return (true);
    return (false);
}