#include "h/misc.hpp"
#include "h/Processor.hpp"

int main(void)
{
    Processor proc;
    std::string str;

    while (true)
    {
        std::getline(std::cin, str);

        if (str == "EXIT")
            return 0;
        else
            proc.Execute(split(str, ' '));
    }

    return -1;
}
