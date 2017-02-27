#include "h/Processor.hpp"

bool Processor::instrJMP(const std::string &strDest)
{
	for (unsigned i = 0; i < m_labelsStr.size(); i++)
	{
		if (m_labelsStr[i] == strDest)
		{
			m_programCounter = m_labelsAddr[i];
			return true;
		}
	}

	errInvalidOperand(strDest);
	return false;
}
