#include "../h/Processor.hpp"

bool Processor::instrDEC(const std::string &strDest)
{
	if (strDest[0] == 'I')
	{
		signed int *pReg = nullptr;
		if (getRegInt(strDest, pReg))
		{
			signed int oldValue = *pReg;
			*pReg -= 1;
			m_flagBorrow = (*pReg > oldValue);
			return true;
		}
	}
	else if (strDest[0] == 'L')
	{
		unsigned long *pReg = nullptr;
		if (getRegLong(strDest, pReg))
		{
			unsigned long oldValue = *pReg;
			*pReg -= 1;
			m_flagBorrow = (*pReg > oldValue);
			return true;
		}
	}

	errInvalidRegister(strDest);
	return false;
}
