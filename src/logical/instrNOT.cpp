#include "../h/Processor.hpp"

bool Processor::instrNOT(const std::string& strDest)
{
    // Destination register is int
    if (strDest[0] == 'I')
    {
        signed int* pRegDest = nullptr;
        if (getRegInt(strDest, pRegDest))
        {
            *pRegDest = ~*pRegDest;
            return true;
        }
    }
    // Destination register is long
    else if (strDest[0] == 'L')
    {
        unsigned long* pRegDest = nullptr;
        if (getRegLong(strDest, pRegDest))
        {
            *pRegDest = ~*pRegDest;
            return true;
        }
    }

    errInvalidRegister(strDest);
    return false;
}
