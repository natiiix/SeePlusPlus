#include "../h/Processor.hpp"

bool Processor::instrCMP(const std::string& strDest, const std::string& strSource)
{
    // Destination register is int
    if (strDest[0] == 'I')
    {
        signed int* pRegDest = nullptr;
        if (getRegInt(strDest, pRegDest))
        {
            // Source register is int
            if (strSource[0] == 'I')
            {
                signed int* pRegSource = nullptr;
                if (getRegInt(strSource, pRegSource))
                {
                    m_flagCarry = (*pRegSource > *pRegDest);
                    m_flagBorrow = (*pRegSource < *pRegDest);
                    m_flagZero = (*pRegSource == *pRegDest);

                    return true;
                }

                errInvalidRegister(strSource);
                return false;
            }
            // Source register is long
            else if (strSource[0] == 'L')
            {
                unsigned long* pRegSource = nullptr;
                if (getRegLong(strSource, pRegSource))
                {
                    m_flagCarry = ((signed int)*pRegSource > *pRegDest);
                    m_flagBorrow = ((signed int)*pRegSource < *pRegDest);
                    m_flagZero = ((signed int)*pRegSource == *pRegDest);

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
                    m_flagCarry = (sourceValue > *pRegDest);
                    m_flagBorrow = (sourceValue < *pRegDest);
                    m_flagZero = (sourceValue == *pRegDest);

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
        unsigned long* pRegDest = nullptr;
        if (getRegLong(strDest, pRegDest))
        {
            // Source register is int
            if (strSource[0] == 'I')
            {
                signed int* pRegSource = nullptr;
                if (getRegInt(strSource, pRegSource))
                {
                    m_flagCarry = (*pRegSource > (signed int)*pRegDest);
                    m_flagBorrow = (*pRegSource < (signed int)*pRegDest);
                    m_flagZero = (*pRegSource == (signed int)*pRegDest);

                    return true;
                }

                errInvalidRegister(strSource);
                return false;
            }
            // Source register is long
            else if (strSource[0] == 'L')
            {
                unsigned long* pRegSource = nullptr;
                if (getRegLong(strSource, pRegSource))
                {
                    m_flagCarry = (*pRegSource > *pRegDest);
                    m_flagBorrow = (*pRegSource < *pRegDest);
                    m_flagZero = (*pRegSource == *pRegDest);

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
                    m_flagCarry = (sourceValue > *pRegDest);
                    m_flagBorrow = (sourceValue < *pRegDest);
                    m_flagZero = (sourceValue == *pRegDest);

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
