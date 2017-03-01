#include "h/Processor.hpp"

bool Processor::instrCLE(const std::string &strDest)
{
	if (m_flagBorrow || m_flagZero)
		return instrCALL(strDest);
	else
		return true;
}
