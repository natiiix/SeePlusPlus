#include "h/misc.hpp"

std::vector<std::string> split(const std::string& strInput, const char separator, const bool removeEmpty)
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

/*std::vector<std::string> split(const std::string& s, char seperator)
{
   std::vector<std::string> output;

    std::string::size_type prev_pos = 0, pos = 0;

    while((pos = s.find(seperator, pos)) != std::string::npos)
    {
        std::string substring( s.substr(prev_pos, pos-prev_pos) );

        output.push_back(substring);

        prev_pos = ++pos;
    }

    output.push_back(s.substr(prev_pos, pos-prev_pos)); // Last word

    return output;
}*/