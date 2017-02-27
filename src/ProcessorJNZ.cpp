#include "h/Processor.hpp"

bool Processor::instrJNZ(const std::string &strDest)
{
	if (!m_flagZero)
		return instrJMP(strDest);
	else
		return true;
}
