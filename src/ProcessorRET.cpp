#include "h/Processor.hpp"

bool Processor::instrRET()
{
	if (m_stack.size() > 0)
	{
		m_programCounter = m_stack.back();
		m_stack.pop_back();
		return true;
	}
	else
	{
		errMessage("Cannot perform RET! Stack is empty!");
		return false;
	}
}
