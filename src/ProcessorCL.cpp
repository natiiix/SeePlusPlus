#include "h/Processor.hpp"

bool Processor::instrCL(const std::string &strDest)
{
	if (m_flagBorrow)
		return instrCALL(strDest);
	else
		return true;
}
