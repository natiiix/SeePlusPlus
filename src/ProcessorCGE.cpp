#include "h/Processor.hpp"

bool Processor::instrCGE(const std::string &strDest)
{
	if (m_flagCarry || m_flagZero)
		return instrCALL(strDest);
	else
		return true;
}
