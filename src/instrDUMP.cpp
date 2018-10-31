#include "h/Processor.hpp"

bool Processor::instrDUMP(const std::string& strReg)
{
    if (strReg[0] == 'I')
    {
        signed int* pReg = nullptr;
        if (getRegInt(strReg, pReg))
        {
            std::cout << *pReg << std::endl;
            return true;
        }
    }
    else if (strReg[0] == 'L')
    {
        unsigned long* pReg = nullptr;
        if (getRegLong(strReg, pReg))
        {
            std::cout << *pReg << std::endl;
            return true;
        }
    }
    else if (strReg[0] == 'Z')
    {
        if (m_flagZero)
            std::cout << "ZERO TRUE" << std::endl;
        else
            std::cout << "ZERO FALSE" << std::endl;

        return true;
    }
    else if (strReg[0] == 'C')
    {
        if (m_flagCarry)
            std::cout << "CARRY TRUE" << std::endl;
        else
            std::cout << "CARRY FALSE" << std::endl;

        return true;
    }
    else if (strReg[0] == 'B')
    {
        if (m_flagBorrow)
            std::cout << "BORROW TRUE" << std::endl;
        else
            std::cout << "BORROW FALSE" << std::endl;

        return true;
    }

    errInvalidRegister(strReg);
    return false;
}

bool Processor::_instrDUMP_BASE(const std::string& strReg, const unsigned& base)
{
    if (strReg[0] == 'I')
    {
        signed int* pReg = nullptr;
        if (getRegInt(strReg, pReg))
        {
            std::cout << SIntToString(*pReg, base) << std::endl;
            return true;
        }
    }
    else if (strReg[0] == 'L')
    {
        unsigned long* pReg = nullptr;
        if (getRegLong(strReg, pReg))
        {
            std::cout << ULongToString(*pReg, base) << std::endl;
            return true;
        }
    }

    errInvalidRegister(strReg);
    return false;
}

bool Processor::instrDUMPB(const std::string& strReg)
{
    return _instrDUMP_BASE(strReg, 2);
}

bool Processor::instrDUMPH(const std::string& strReg)
{
    return _instrDUMP_BASE(strReg, 16);
}
