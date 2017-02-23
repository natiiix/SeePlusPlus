#include "h/Processor.hpp"

Processor::Processor()
{
<<<<<<< HEAD
    clearFlags();
=======
	clearFlags();
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
}

bool Processor::Execute(const std::vector<std::string> &command)
{	
    if (command.size() <= 0)
        return false;

    // Custom instructions
    if (command[0] == "DUMP" && command.size() == 2) return instrDUMP(command[1]);
	
    // x86 instrunctions
<<<<<<< HEAD
    if (command[0] == "MOV" && command.size() == 3)
        return instrMOV(command[1], command[2]);
    if (command[0] == "INC" && command.size() == 2)
        return instrINC(command[1]);
    if (command[0] == "DEC" && command.size() == 2)
        return instrDEC(command[1]);
    if (command[0] == "ADD" && command.size() == 3)
        return instrADD(command[1], command[2]);
    if (command[0] == "ADC" && command.size() == 2)
        return instrADC(command[1]);
    if (command[0] == "ADC" && command.size() == 3)
        return instrADC(command[1], command[2]);
    if (command[0] == "SUB" && command.size() == 3)
        return instrSUB(command[1], command[2]);
    if (command[0] == "SBB" && command.size() == 2)
        return instrSBB(command[1]);
    if (command[0] == "SBB" && command.size() == 3)
        return instrSBB(command[1], command[2]);
=======
    if (command[0] == "MOV" && command.size() == 3) return instrMOV(command[1], command[2]);
    if (command[0] == "INC" && command.size() == 2) return instrINC(command[1]);
    if (command[0] == "DEC" && command.size() == 2) return instrDEC(command[1]);
	if (command[0] == "ADD" && command.size() == 3) return instrADD(command[1], command[2]);
	if (command[0] == "ADC" && command.size() == 2) return instrADC(command[1]);
	if (command[0] == "ADC" && command.size() == 3) return instrADC(command[1], command[2]);
	if (command[0] == "SUB" && command.size() == 3) return instrSUB(command[1], command[2]);
	if (command[0] == "SBB" && command.size() == 2) return instrSBB(command[1]);
	if (command[0] == "SBB" && command.size() == 3) return instrSBB(command[1], command[2]);
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889

    // Unrecognized instruction
    std::cout << "Invalid instruction! (";
    for (int i = 0; i < (int)command.size(); i++)
    {
        if (i > 0)
            std::cout << " ";

        std::cout << command[i];
    }
    std::cout << ")" << std::endl;

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

void Processor::clearFlags()
<<<<<<< HEAD
{
    flagCarry = false;
    flagBorrow = false;
}

bool Processor::instrDUMP(const std::string &strReg)
=======
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
{
	flagCarry = false;
	flagBorrow = false;
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
<<<<<<< HEAD
    else if (strReg[0] == 'C')
    {
        if (flagCarry)
            std::cout << "CARRY TRUE" << std::endl;
        else
            std::cout << "CARRY FALSE" << std::endl;

        return true;
    }
    else if (strReg[0] == 'B')
    {
        if (flagBorrow)
            std::cout << "BORROW TRUE" << std::endl;
        else
            std::cout << "BORROW FALSE" << std::endl;

        return true;
    }
=======
	else if (strReg[0] == 'C')
	{
		if (flagCarry)
			std::cout << "CARRY TRUE" << std::endl;
		else
			std::cout << "CARRY FALSE" << std::endl;

		return true;
	}
	else if (strReg[0] == 'B')
	{
		if (flagBorrow)
			std::cout << "BORROW TRUE" << std::endl;
		else
			std::cout << "BORROW FALSE" << std::endl;

		return true;
	}
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889

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
<<<<<<< HEAD
                /*std::istringstream iss(strSource);
                unsigned int sourceValue = 0;
=======
                std::istringstream iss(strSource);
                signed int sourceValue = 0;
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
                if (iss >> sourceValue)
                {
                    *pRegDest = (signed int)sourceValue;
                    return true;
                }*/

                if (strSIntTryParse(strSource, *pRegDest))
                    return true;
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
<<<<<<< HEAD
                /*std::istringstream iss(strSource);
=======
                std::istringstream iss(strSource);
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
                signed int sourceValue = 0;
                if (iss >> sourceValue)
                {
                    *pRegDest = (unsigned long)sourceValue;
                    return true;
                }*/

                if (strULongTryParse(strSource, *pRegDest))
                    return true;
            }

            errInvalidOperand(strSource);
            return false;
        }
    }

    errInvalidRegister(strDest);
    return false;
}

bool Processor::instrINC(const std::string &strDest)
{
    if (strDest[0] == 'I')
    {
        signed int *pReg = nullptr;
        if (getRegInt(strDest, pReg))
        {
            signed int oldValue = *pReg;
            *pReg += 1;
            flagCarry = (*pReg < oldValue);
            return true;
        }
    }
    else if (strDest[0] == 'L')
    {
        unsigned long *pReg = nullptr;
        if (getRegLong(strDest, pReg))
        {
            unsigned long oldValue = *pReg;
            *pReg += 1;
            flagCarry = (*pReg < oldValue);
            return true;
        }
    }

    errInvalidRegister(strDest);
    return false;
}

bool Processor::instrDEC(const std::string &strDest)
{
    if (strDest[0] == 'I')
    {
        signed int *pReg = nullptr;
        if (getRegInt(strDest, pReg))
        {
            signed int oldValue = *pReg;
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
            *pReg -= 1;
            flagBorrow = (*pReg > oldValue);
            return true;
        }
    }

    errInvalidRegister(strDest);
    return false;
}

bool Processor::instrADD(const std::string &strDest, const std::string &strSource)
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
                    *pRegDest += *pRegSource;

                    if (*pRegSource >= 0)
                    {
                        flagCarry = (*pRegDest < oldValue);
                        flagBorrow = false;
                    }
                    else
                    {
                        flagCarry = false;
                        flagBorrow = (*pRegDest > oldValue);
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
                    *pRegDest += (signed int)*pRegSource;

                    if (*pRegSource >= 0)
                    {
                        flagCarry = (*pRegDest < oldValue);
                        flagBorrow = false;
                    }
                    else
                    {
                        flagCarry = false;
                        flagBorrow = (*pRegDest > oldValue);
                    }

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
                    *pRegDest += sourceValue;

                    if (sourceValue >= 0)
                    {
                        flagCarry = (*pRegDest < oldValue);
                        flagBorrow = false;
                    }
                    else
                    {
                        flagCarry = false;
                        flagBorrow = (*pRegDest > oldValue);
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
                    *pRegDest += (unsigned long)*pRegSource;

                    if (*pRegSource >= 0)
                    {
                        flagCarry = (*pRegDest < oldValue);
                        flagBorrow = false;
                    }
                    else
                    {
                        flagCarry = false;
                        flagBorrow = (*pRegDest > oldValue);
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
                    *pRegDest += *pRegSource;

                    if (*pRegSource >= 0)
                    {
                        flagCarry = (*pRegDest < oldValue);
                        flagBorrow = false;
                    }
                    else
                    {
                        flagCarry = false;
                        flagBorrow = (*pRegDest > oldValue);
                    }

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
                    *pRegDest += sourceValue;

                    if (sourceValue >= 0)
                    {
                        flagCarry = (*pRegDest < oldValue);
                        flagBorrow = false;
                    }
                    else
                    {
                        flagCarry = false;
                        flagBorrow = (*pRegDest > oldValue);
                    }

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

<<<<<<< HEAD
bool Processor::instrADC(const std::string &strDest)
{
    if (strDest[0] == 'I')
    {
        signed int *pReg = nullptr;
        if (getRegInt(strDest, pReg))
        {
            signed int oldValue = *pReg;
            if (flagCarry)
                *pReg += 1;
            flagCarry = (*pReg < oldValue);
            return true;
        }
    }
    else if (strDest[0] == 'L')
    {
        unsigned long *pReg = nullptr;
        if (getRegLong(strDest, pReg))
        {
            unsigned long oldValue = *pReg;
            if (flagCarry)
                *pReg += 1;
            flagCarry = (*pReg < oldValue);
            return true;
=======
bool Processor::instrINC(const std::string &strDest)
{	
    if (strDest[0] == 'I')
    {
        signed int *pReg = nullptr;
        if (getRegInt(strDest, pReg))
        {
			signed int oldValue = *pReg;
            *pReg += 1;
			flagCarry = (*pReg < oldValue);
            return true;
        }
    }
    else if (strDest[0] == 'L')
    {
        unsigned long *pReg = nullptr;
        if (getRegLong(strDest, pReg))
        {
			unsigned long oldValue = *pReg;
            *pReg += 1;
			flagCarry = (*pReg < oldValue);
            return true;
        }
    }

    errInvalidRegister(strDest);
    return false;
}

bool Processor::instrDEC(const std::string &strDest)
{	
    if (strDest[0] == 'I')
    {
        signed int *pReg = nullptr;
        if (getRegInt(strDest, pReg))
        {
			signed int oldValue = *pReg;
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
            *pReg -= 1;
			flagBorrow = (*pReg > oldValue);
            return true;
        }
    }

    errInvalidRegister(strDest);
    return false;
}

bool Processor::instrADD(const std::string &strDest, const std::string &strSource)
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
                    *pRegDest += *pRegSource;
					
					if (*pRegSource >= 0)
					{
						flagCarry = (*pRegDest < oldValue);
						flagBorrow = false;
					}
					else
					{
						flagCarry = false;
						flagBorrow = (*pRegDest > oldValue);
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
                    *pRegDest += (signed int)*pRegSource;
					
					if (*pRegSource >= 0)
					{
						flagCarry = (*pRegDest < oldValue);
						flagBorrow = false;
					}
					else
					{
						flagCarry = false;
						flagBorrow = (*pRegDest > oldValue);
					}
					
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
                    *pRegDest += sourceValue;
					
					if (sourceValue >= 0)
					{
						flagCarry = (*pRegDest < oldValue);
						flagBorrow = false;
					}
					else
					{
						flagCarry = false;
						flagBorrow = (*pRegDest > oldValue);
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
                    *pRegDest += (unsigned long)*pRegSource;
					
					if (*pRegSource >= 0)
					{
						flagCarry = (*pRegDest < oldValue);
						flagBorrow = false;
					}
					else
					{
						flagCarry = false;
						flagBorrow = (*pRegDest > oldValue);
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
                    *pRegDest += *pRegSource;
					
					if (*pRegSource >= 0)
					{
						flagCarry = (*pRegDest < oldValue);
						flagBorrow = false;
					}
					else
					{
						flagCarry = false;
						flagBorrow = (*pRegDest > oldValue);
					}
					
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
                    *pRegDest += sourceValue;
					
					if (sourceValue >= 0)
					{
						flagCarry = (*pRegDest < oldValue);
						flagBorrow = false;
					}
					else
					{
						flagCarry = false;
						flagBorrow = (*pRegDest > oldValue);
					}
					
                    return true;
                }
            }

            errInvalidOperand(strSource);
            return false;
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
        }
    }

    errInvalidRegister(strDest);
    return false;
}

<<<<<<< HEAD
bool Processor::instrADC(const std::string &strDest, const std::string &strSource)
{
=======
bool Processor::instrADC(const std::string &strDest)
{
    if (strDest[0] == 'I')
    {
        signed int *pReg = nullptr;
        if (getRegInt(strDest, pReg))
        {
			signed int oldValue = *pReg;
            if (flagCarry)
				*pReg += 1;
			flagCarry = (*pReg < oldValue);
            return true;
        }
    }
    else if (strDest[0] == 'L')
    {
        unsigned long *pReg = nullptr;
        if (getRegLong(strDest, pReg))
        {
			unsigned long oldValue = *pReg;
            if (flagCarry)
				*pReg += 1;
			flagCarry = (*pReg < oldValue);
            return true;
        }
    }

    errInvalidRegister(strDest);
    return false;
}

bool Processor::instrADC(const std::string &strDest, const std::string &strSource)
{
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
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
<<<<<<< HEAD
                    signed int oldValue = *pRegDest;
                    *pRegDest += *pRegSource;
                    if (flagCarry)
                        *pRegDest += 1;

                    if (*pRegSource >= 0)
                    {
                        flagCarry = (*pRegDest < oldValue);
                        flagBorrow = false;
                    }
                    else
                    {
                        flagCarry = false;
                        flagBorrow = (*pRegDest > oldValue);
                    }

=======
					signed int oldValue = *pRegDest;
                    *pRegDest += *pRegSource;
					if (flagCarry)
						*pRegDest += 1;
					
					if (*pRegSource >= 0)
					{
						flagCarry = (*pRegDest < oldValue);
						flagBorrow = false;
					}
					else
					{
						flagCarry = false;
						flagBorrow = (*pRegDest > oldValue);
					}
					
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
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
<<<<<<< HEAD
                    signed int oldValue = *pRegDest;
                    *pRegDest += (signed int)*pRegSource;
                    if (flagCarry)
                        *pRegDest += 1;

                    if (*pRegSource >= 0)
                    {
                        flagCarry = (*pRegDest < oldValue);
                        flagBorrow = false;
                    }
                    else
                    {
                        flagCarry = false;
                        flagBorrow = (*pRegDest > oldValue);
                    }

=======
					signed int oldValue = *pRegDest;
                    *pRegDest += (signed int)*pRegSource;
					if (flagCarry)
						*pRegDest += 1;
					
					if (*pRegSource >= 0)
					{
						flagCarry = (*pRegDest < oldValue);
						flagBorrow = false;
					}
					else
					{
						flagCarry = false;
						flagBorrow = (*pRegDest > oldValue);
					}
					
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
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
<<<<<<< HEAD
                    signed int oldValue = *pRegDest;
                    *pRegDest += sourceValue;
                    if (flagCarry)
                        *pRegDest += 1;

                    if (sourceValue >= 0)
                    {
                        flagCarry = (*pRegDest < oldValue);
                        flagBorrow = false;
                    }
                    else
                    {
                        flagCarry = false;
                        flagBorrow = (*pRegDest > oldValue);
                    }

=======
					signed int oldValue = *pRegDest;
                    *pRegDest += sourceValue;
					if (flagCarry)
						*pRegDest += 1;
					
					if (sourceValue >= 0)
					{
						flagCarry = (*pRegDest < oldValue);
						flagBorrow = false;
					}
					else
					{
						flagCarry = false;
						flagBorrow = (*pRegDest > oldValue);
					}
					
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
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
<<<<<<< HEAD
                    unsigned long oldValue = *pRegDest;
                    *pRegDest += (unsigned long)*pRegSource;
                    if (flagCarry)
                        *pRegDest += 1;

                    if (*pRegSource >= 0)
                    {
                        flagCarry = (*pRegDest < oldValue);
                        flagBorrow = false;
                    }
                    else
                    {
                        flagCarry = false;
                        flagBorrow = (*pRegDest > oldValue);
                    }

=======
					unsigned long oldValue = *pRegDest;
                    *pRegDest += (unsigned long)*pRegSource;
					if (flagCarry)
						*pRegDest += 1;
					
					if (*pRegSource >= 0)
					{
						flagCarry = (*pRegDest < oldValue);
						flagBorrow = false;
					}
					else
					{
						flagCarry = false;
						flagBorrow = (*pRegDest > oldValue);
					}
					
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
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
<<<<<<< HEAD
                    unsigned long oldValue = *pRegDest;
                    *pRegDest += *pRegSource;
                    if (flagCarry)
                        *pRegDest += 1;

                    if (*pRegSource >= 0)
                    {
                        flagCarry = (*pRegDest < oldValue);
                        flagBorrow = false;
                    }
                    else
                    {
                        flagCarry = false;
                        flagBorrow = (*pRegDest > oldValue);
                    }

=======
					unsigned long oldValue = *pRegDest;
                    *pRegDest += *pRegSource;
					if (flagCarry)
						*pRegDest += 1;
					
					if (*pRegSource >= 0)
					{
						flagCarry = (*pRegDest < oldValue);
						flagBorrow = false;
					}
					else
					{
						flagCarry = false;
						flagBorrow = (*pRegDest > oldValue);
					}
					
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
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
<<<<<<< HEAD
                    unsigned long oldValue = *pRegDest;
                    *pRegDest += sourceValue;
                    if (flagCarry)
                        *pRegDest += 1;

                    if (sourceValue >= 0)
                    {
                        flagCarry = (*pRegDest < oldValue);
                        flagBorrow = false;
                    }
                    else
                    {
                        flagCarry = false;
                        flagBorrow = (*pRegDest > oldValue);
                    }

=======
					unsigned long oldValue = *pRegDest;
                    *pRegDest += sourceValue;
					if (flagCarry)
						*pRegDest += 1;
					
					if (sourceValue >= 0)
					{
						flagCarry = (*pRegDest < oldValue);
						flagBorrow = false;
					}
					else
					{
						flagCarry = false;
						flagBorrow = (*pRegDest > oldValue);
					}
					
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
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

bool Processor::instrSUB(const std::string &strDest, const std::string &strSource)
{
<<<<<<< HEAD
    // Destination register is int
=======
	// Destination register is int
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
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
<<<<<<< HEAD
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

=======
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
					
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
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
<<<<<<< HEAD
                    signed int oldValue = *pRegDest;
                    *pRegDest -= (signed int)*pRegSource;

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

=======
					signed int oldValue = *pRegDest;
                    *pRegDest -= (signed int)*pRegSource;
					
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
					
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
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
<<<<<<< HEAD
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

=======
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
					
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
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
<<<<<<< HEAD
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

=======
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
					
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
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
<<<<<<< HEAD
                    unsigned long oldValue = *pRegDest;
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

=======
					unsigned long oldValue = *pRegDest;
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
					
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
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
<<<<<<< HEAD
                    unsigned long oldValue = *pRegDest;
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

=======
					unsigned long oldValue = *pRegDest;
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
					
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
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

bool Processor::instrSBB(const std::string &strDest)
{
<<<<<<< HEAD
    if (strDest[0] == 'I')
=======
	if (strDest[0] == 'I')
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
    {
        signed int *pReg = nullptr;
        if (getRegInt(strDest, pReg))
        {
<<<<<<< HEAD
            signed int oldValue = *pReg;
            if (flagBorrow)
                *pReg -= 1;
            flagBorrow = (*pReg > oldValue);
=======
			signed int oldValue = *pReg;
			if (flagBorrow)
				*pReg -= 1;
			flagBorrow = (*pReg > oldValue);
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
            return true;
        }
    }
    else if (strDest[0] == 'L')
    {
        unsigned long *pReg = nullptr;
        if (getRegLong(strDest, pReg))
        {
<<<<<<< HEAD
            unsigned long oldValue = *pReg;
            if (flagBorrow)
                *pReg -= 1;
            flagBorrow = (*pReg > oldValue);
=======
			unsigned long oldValue = *pReg;
			if (flagBorrow)
				*pReg -= 1;
			flagBorrow = (*pReg > oldValue);
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
            return true;
        }
    }

    errInvalidRegister(strDest);
    return false;
}

bool Processor::instrSBB(const std::string &strDest, const std::string &strSource)
<<<<<<< HEAD
{
    // Destination register is int
=======
{	
	// Destination register is int
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
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
<<<<<<< HEAD
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

=======
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
					
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
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
<<<<<<< HEAD
                    signed int oldValue = *pRegDest;
                    *pRegDest -= (signed int)*pRegSource;
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

=======
					signed int oldValue = *pRegDest;
                    *pRegDest -= (signed int)*pRegSource;
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
					
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
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
<<<<<<< HEAD
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

=======
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
					
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
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
<<<<<<< HEAD
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

=======
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
					
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
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
<<<<<<< HEAD
                    unsigned long oldValue = *pRegDest;
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

=======
					unsigned long oldValue = *pRegDest;
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
					
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
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
<<<<<<< HEAD
                    unsigned long oldValue = *pRegDest;
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

=======
					unsigned long oldValue = *pRegDest;
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
					
>>>>>>> e1f8f6463e256d38ffe7ec1e360a7d53566a8889
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