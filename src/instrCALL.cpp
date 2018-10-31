#include "h/Processor.hpp"

bool Processor::instrCALL(const std::string& strDest)
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

bool Processor::instrCZ(const std::string& strDest)
{
    if (m_flagZero)
        return instrCALL(strDest);
    else
        return true;
}

bool Processor::instrCNZ(const std::string& strDest)
{
    if (!m_flagZero)
        return instrCALL(strDest);
    else
        return true;
}

bool Processor::instrCG(const std::string& strDest)
{
    if (m_flagCarry)
        return instrCALL(strDest);
    else
        return true;
}

bool Processor::instrCGE(const std::string& strDest)
{
    if (m_flagCarry || m_flagZero)
        return instrCALL(strDest);
    else
        return true;
}

bool Processor::instrCL(const std::string& strDest)
{
    if (m_flagBorrow)
        return instrCALL(strDest);
    else
        return true;
}

bool Processor::instrCLE(const std::string& strDest)
{
    if (m_flagBorrow || m_flagZero)
        return instrCALL(strDest);
    else
        return true;
}
