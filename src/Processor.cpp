#include "h/Processor.hpp"

Processor::Processor()
{
    clearFlags();
}

bool Processor::Execute(const std::vector<std::string> &command)
{
    if (command.size() <= 0)
        return false;

    // Custom instructions
    if (command[0] == "DUMP" && command.size() == 2) return instrDUMP(command[1]);

    // x86 instrunctions
    if (command[0] == "MOV" && command.size() == 3) return instrMOV(command[1], command[2]);
    if (command[0] == "INC" && command.size() == 2) return instrINC(command[1]);
    if (command[0] == "DEC" && command.size() == 2) return instrDEC(command[1]);
    if (command[0] == "ADD" && command.size() == 3) return instrADD(command[1], command[2]);
    if (command[0] == "ADC" && command.size() == 2) return instrADC(command[1]);
    if (command[0] == "ADC" && command.size() == 3) return instrADC(command[1], command[2]);
    if (command[0] == "SUB" && command.size() == 3) return instrSUB(command[1], command[2]);
    if (command[0] == "SBB" && command.size() == 2) return instrSBB(command[1]);
    if (command[0] == "SBB" && command.size() == 3) return instrSBB(command[1], command[2]);

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
{
    flagCarry = false;
    flagBorrow = false;
}
