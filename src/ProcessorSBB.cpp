#include "h/Processor.hpp"

bool Processor::instrSBB(const std::string &strDest)
{
    if (strDest[0] == 'I')
    {
        signed int *pReg = nullptr;
        if (getRegInt(strDest, pReg))
        {
            signed int oldValue = *pReg;
            if (flagBorrow)
                *pReg -= 1;
            flagBorrow = (*pReg > oldValue);
            return true;
        }
    }
    else if (strDest[0] == 'L')
    {
        unsigned long *pReg = nullptr;
        if (getRegLong(strDest, pReg))
        {
            unsigned long oldValue = *pReg;
            if (flagBorrow)
                *pReg -= 1;
            flagBorrow = (*pReg > oldValue);
            return true;
        }
    }

    errInvalidRegister(strDest);
    return false;
}

bool Processor::instrSBB(const std::string &strDest, const std::string &strSource)
{
    // Destination register is int
    if (strDest[0] == 'I')
    {
        signed int *pRegDest = nullptr;
        if (getRegInt(strDest, pRegDest))
        {
            // Source register is int
            if (strSource[0] == 'I')
            {
                signed int *pRegSource = nullptr;
                if (getRegInt(strSource, pRegSource))
                {
                    signed int oldValue = *pRegDest;
                    *pRegDest -= *pRegSource;
                    if (flagBorrow)
                        *pRegDest -= 1;

                    if (*pRegSource >= 0)
                    {
                        flagCarry = false;
                        flagBorrow = (*pRegDest > oldValue);
                    }
                    else
                    {
                        flagCarry = (*pRegDest < oldValue);
                        flagBorrow = false;
                    }

                    return true;
                }

                errInvalidRegister(strSource);
                return false;
            }
            // Source register is long
            else if (strSource[0] == 'L')
            {
                unsigned long *pRegSource = nullptr;
                if (getRegLong(strSource, pRegSource))
                {
                    signed int oldValue = *pRegDest;
                    *pRegDest -= (signed int)*pRegSource;
                    if (flagBorrow)
                        *pRegDest -= 1;

                    flagCarry = false;
                    flagBorrow = (*pRegDest > oldValue);

                    return true;
                }

                errInvalidRegister(strSource);
                return false;
            }
            // Source is a literal value
            else
            {
                std::istringstream iss(strSource);
                signed int sourceValue = 0;
                if (iss >> sourceValue)
                {
                    signed int oldValue = *pRegDest;
                    *pRegDest -= sourceValue;
                    if (flagBorrow)
                        *pRegDest -= 1;

                    if (sourceValue >= 0)
                    {
                        flagCarry = false;
                        flagBorrow = (*pRegDest > oldValue);
                    }
                    else
                    {
                        flagCarry = (*pRegDest < oldValue);
                        flagBorrow = false;
                    }

                    return true;
                }
            }

            errInvalidOperand(strSource);
            return false;
        }
    }
    // Destination register is long
    else if (strDest[0] == 'L')
    {
        unsigned long *pRegDest = nullptr;
        if (getRegLong(strDest, pRegDest))
        {
            // Source register is int
            if (strSource[0] == 'I')
            {
                signed int *pRegSource = nullptr;
                if (getRegInt(strSource, pRegSource))
                {
                    unsigned long oldValue = *pRegDest;
                    *pRegDest -= (unsigned long)*pRegSource;
                    if (flagBorrow)
                        *pRegDest -= 1;

                    if (*pRegSource >= 0)
                    {
                        flagCarry = false;
                        flagBorrow = (*pRegDest > oldValue);
                    }
                    else
                    {
                        flagCarry = (*pRegDest < oldValue);
                        flagBorrow = false;
                    }

                    return true;
                }

                errInvalidRegister(strSource);
                return false;
            }
            // Source register is long
            else if (strSource[0] == 'L')
            {
                unsigned long *pRegSource = nullptr;
                if (getRegLong(strSource, pRegSource))
                {
                    unsigned long oldValue = *pRegDest;
                    *pRegDest -= *pRegSource;
                    if (flagBorrow)
                        *pRegDest -= 1;

                    flagCarry = false;
                    flagBorrow = (*pRegDest > oldValue);

                    return true;
                }

                errInvalidRegister(strSource);
                return false;
            }
            // Source is a literal value
            else
            {
                std::istringstream iss(strSource);
                unsigned long sourceValue = 0;
                if (iss >> sourceValue)
                {
                    unsigned long oldValue = *pRegDest;
                    *pRegDest -= sourceValue;
                    if (flagBorrow)
                        *pRegDest -= 1;

                    flagCarry = false;
                    flagBorrow = (*pRegDest > oldValue);

                    return true;
                }
            }

            errInvalidOperand(strSource);
            return false;
        }
    }

    errInvalidRegister(strDest);
    return false;
}
