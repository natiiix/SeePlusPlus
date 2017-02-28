#include "h/Processor.hpp"

bool Processor::instrCNZ(const std::string &strDest)
{
	if (!m_flagZero)
		return instrCALL(strDest);
	else
		return true;
}
