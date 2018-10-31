#include "h/Processor.hpp"

bool Processor::instrJMP(const std::string& strDest)
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

bool Processor::instrJZ(const std::string& strDest)
{
    if (m_flagZero)
        return instrJMP(strDest);
    else
        return true;
}

bool Processor::instrJNZ(const std::string& strDest)
{
    if (!m_flagZero)
        return instrJMP(strDest);
    else
        return true;
}

bool Processor::instrJG(const std::string& strDest)
{
    if (m_flagCarry)
        return instrJMP(strDest);
    else
        return true;
}

bool Processor::instrJGE(const std::string& strDest)
{
    if (m_flagCarry || m_flagZero)
        return instrJMP(strDest);
    else
        return true;
}

bool Processor::instrJL(const std::string& strDest)
{
    if (m_flagBorrow)
        return instrJMP(strDest);
    else
        return true;
}

bool Processor::instrJLE(const std::string& strDest)
{
    if (m_flagBorrow || m_flagZero)
        return instrJMP(strDest);
    else
        return true;
}
