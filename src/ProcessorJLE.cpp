#include "h/Processor.hpp"

bool Processor::instrJLE(const std::string &strDest)
{
	if (m_flagBorrow || m_flagZero)
		return instrJMP(strDest);
	else
		return true;
}
