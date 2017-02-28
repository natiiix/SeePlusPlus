#include "h/Processor.hpp"

bool Processor::instrJG(const std::string &strDest)
{
	if (m_flagCarry)
		return instrJMP(strDest);
	else
		return true;
}
