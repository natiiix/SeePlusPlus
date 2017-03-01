#include "h/Processor.hpp"

bool Processor::instrCG(const std::string &strDest)
{
	if (m_flagCarry)
		return instrCALL(strDest);
	else
		return true;
}
