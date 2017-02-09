#include "h/misc.hpp"

std::vector<std::string> split(const std::string &strInput, const char separator, const bool removeEmpty)
{
    std::vector<std::string> strings;
    std::istringstream strstream(strInput);

    std::string sTemp;
    while (getline(strstream, sTemp, separator))
    {
        if (!removeEmpty || sTemp.length() > 0)
        {
            strings.push_back(sTemp);
        }
    }

    return strings;
}