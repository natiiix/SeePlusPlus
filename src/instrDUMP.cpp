#include "h/Processor.hpp"

bool Processor::instrDUMP(const std::string &strReg)
{
	if (strReg[0] == 'I')
	{
		signed int *pReg = nullptr;
		if (getRegInt(strReg, pReg))
		{
			std::cout << *pReg << std::endl;
			return true;
		}
	}
	else if (strReg[0] == 'L')
	{
		unsigned long *pReg = nullptr;
		if (getRegLong(strReg, pReg))
		{
			std::cout << *pReg << std::endl;
			return true;
		}
	}
	else if (strReg[0] == 'C')
	{
		if (m_flagCarry)
			std::cout << "CARRY TRUE" << std::endl;
		else
			std::cout << "CARRY FALSE" << std::endl;

		return true;
	}
	else if (strReg[0] == 'B')
	{
		if (m_flagBorrow)
			std::cout << "BORROW TRUE" << std::endl;
		else
			std::cout << "BORROW FALSE" << std::endl;

		return true;
	}

	errInvalidRegister(strReg);
	return false;
}
