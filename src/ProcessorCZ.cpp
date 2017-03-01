#include "h/Processor.hpp"

bool Processor::instrCZ(const std::string &strDest)
{
	if (m_flagZero)
		return instrCALL(strDest);
	else
		return true;
}
