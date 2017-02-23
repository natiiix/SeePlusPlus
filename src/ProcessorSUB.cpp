#include "h/Processor.hpp"

bool Processor::instrSUB(const std::string &strDest, const std::string &strSource)
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
