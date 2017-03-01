#include "h/Processor.hpp"

bool Processor::instrJL(const std::string &strDest)
{
	if (m_flagBorrow)
		return instrJMP(strDest);
	else
		return true;
}
