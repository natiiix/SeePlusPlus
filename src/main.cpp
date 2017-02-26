#include "h/misc.hpp"
#include "h/Processor.hpp"

int main(void)
{
	Processor proc;
	std::string str;

	while (true)
	{
		std::getline(std::cin, str);

		if (strToUpper(str) == "EXIT")
			return 0;
		else
			proc.ExecuteInstruction(split(str, ' '));
	}

	return -1;
}
