#include "h/Processor.hpp"

bool Processor::instrJGE(const std::string &strDest)
{
	if (m_flagCarry || m_flagZero)
		return instrJMP(strDest);
	else
		return true;
}
