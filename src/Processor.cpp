#include "h/Processor.hpp"
#include <sstream>

Processor::Processor()
{
}

bool Processor::Execute(const std::vector<std::string> &command)
{
    if (command.size() <= 0)
        return false;

    // Custom instructions
    if (command[0] == "DUMP" && command.size() == 2)
        return instrDUMP(command[1]);

    // x86 instrunctions
    if (command[0] == "MOV" && command.size() == 3)
        return instrMOV(command[1], command[2]);

    // Unrecognized instruction
    std::cout << "Invalid instruction! (";
    for (int i = 0; i < command.size(); i++)
    {
        if (i > 0)
            std::cout << " ";

        std::cout << command[i];
    }
    std::cout << ")" << std::endl;

    return false;
}

int Processor::getRegIndex(const std::string &strReg)
{
    if (strReg[0] == 'I' || strReg[0] == 'L')
    {
        std::istringstream iss(strReg.substr(1));
        int regIndex = 0;
        if (iss >> regIndex && regIndex >= 0 && regIndex < REG_WIDTH)
            return regIndex;
    }

    return -1;
}

bool Processor::getRegInt(const std::string &strReg, signed int *&pReg)
{
    int regIndex = getRegIndex(strReg);
    pReg = &regInt[regIndex];
    return (regIndex >= 0);
}

bool Processor::getRegLong(const std::string &strReg, unsigned long *&pReg)
{
    int regIndex = getRegIndex(strReg);
    pReg = &regLong[regIndex];
    return (regIndex >= 0);
}

bool Processor::instrDUMP(const std::string &strReg)
{
    if (strReg[0] == 'I')
    {
        signed int *pReg = nullptr;
        if (getRegInt(strReg, pReg))
        {
            std::cout << *pReg << std::endl;
            return true;
        }
    }
    else if (strReg[0] == 'L')
    {
        unsigned long *pReg = nullptr;
        if (getRegLong(strReg, pReg))
        {
            std::cout << *pReg << std::endl;
            return true;
        }
    }

    errInvalidRegister(strReg);
    return false;
}

bool Processor::instrMOV(const std::string &strDest, const std::string &strSource)
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
                    *pRegDest = *pRegSource;
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
                    *pRegDest = (signed int)*pRegSource;
                    return true;
                }

                errInvalidRegister(strSource);
                return false;
            }
            // Source is a literal value
            else
            {
                std::istringstream iss(strSource);
                int sourceValue = 0;
                if (iss >> sourceValue)
                {
                    *pRegDest = sourceValue;
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
                    *pRegDest = (unsigned long)*pRegSource;
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
                    *pRegDest = *pRegSource;
                    return true;
                }

                errInvalidRegister(strSource);
                return false;
            }
            // Source is a literal value
            else
            {
                std::istringstream iss(strSource);
                int sourceValue = 0;
                if (iss >> sourceValue)
                {
                    *pRegDest = (unsigned long)sourceValue;
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

void Processor::errInvalidRegister(const std::string &strReg)
{
    std::cout << "Ivalid register! (" << strReg << ")" << std::endl;
}

void Processor::errInvalidOperand(const std::string &strOperand)
{
    std::cout << "Ivalid operand! (" << strOperand << ")" << std::endl;
}