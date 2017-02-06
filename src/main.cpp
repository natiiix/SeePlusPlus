#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "h/misc.hpp"

int main(void)
{   
    std::string str;
    std::getline(std::cin, str);

    std::vector<std::string> strVec = split(str, ' ', true);

    std::cout << strVec.size() << std::endl;
    while(!strVec.empty())
    {
        std::cout << strVec.back() << std::endl;
        strVec.pop_back();
    }

    return 0;
}
