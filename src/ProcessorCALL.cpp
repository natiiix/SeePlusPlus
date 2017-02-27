#include "h/Processor.hpp"

bool Processor::instrCALL(const std::string &strDest)
{
	unsigned programCounterOld = m_programCounter;

	if (instrJMP(strDest))
	{
		m_stack.push_back(programCounterOld);
		return true;
	}
	else
		return false;
}
