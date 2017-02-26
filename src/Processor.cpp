#include "h/Processor.hpp"

// Initializes the processor
Processor::Processor(void)
{
	resetProcessor();
}

// Loads a set of processor instructions from program file into the program memory vector
bool Processor::LoadProgram(const std::string &filepath)
{
	resetProcessor();

	std::ifstream file(filepath);

	// File could not have been loaded
	// Most likely cause: file doesn't exist / insufficient permissions
	if (file.fail())
		return false;

	std::string strInstruction;
	while (std::getline(file, strInstruction))
	{
		// Ignore empty lines
		if (strInstruction.size() > 0 &&
			// Ignore commented out lines
			!strBeginsWith(strInstruction, "#") &&
			!strBeginsWith(strInstruction, ";") &&
			!strBeginsWith(strInstruction, "//"))
			// Push the instruction into program memory
			m_program.push_back(strInstruction);
	}

	file.close();

	return true;
}

bool Processor::ExecuteProgram(void)
{
	return false;
}

// Executes an instruction
bool Processor::ExecuteInstruction(const std::vector<std::string> &instruction)
{
	if (instruction.size() <= 0)
		return false;

	std::string opcode = strToUpper(instruction[0]);

	// Custom instructions
	if (opcode == "DUMP" &&instruction.size() == 2) return instrDUMP(instruction[1]);

	// x86 instrunctions
	if (opcode == "MOV" &&instruction.size() == 3) return instrMOV(instruction[1], instruction[2]);
	if (opcode == "INC" &&instruction.size() == 2) return instrINC(instruction[1]);
	if (opcode == "DEC" &&instruction.size() == 2) return instrDEC(instruction[1]);
	if (opcode == "ADD" &&instruction.size() == 3) return instrADD(instruction[1], instruction[2]);
	if (opcode == "ADC" &&instruction.size() == 2) return instrADC(instruction[1]);
	if (opcode == "ADC" &&instruction.size() == 3) return instrADC(instruction[1], instruction[2]);
	if (opcode == "SUB" &&instruction.size() == 3) return instrSUB(instruction[1], instruction[2]);
	if (opcode == "SBB" &&instruction.size() == 2) return instrSBB(instruction[1]);
	if (opcode == "SBB" &&instruction.size() == 3) return instrSBB(instruction[1], instruction[2]);

	// Unrecognized instruction
	errInvalidInstruction(instruction);

	return false;
}

// Prints a message representing the recently occurred exception
void Processor::errMessage(const std::string &msg)
{
	std::cout << "Error occurred: " << msg << std::endl;
}

// Prints "invalid instruction" error
void Processor::errInvalidInstruction(const std::vector<std::string> &instruction)
{
	std::cout << "Invalid instruction: ";
	for (int i = 0; i < (int)instruction.size(); i++)
	{
		if (i > 0)
			std::cout << " ";

		std::cout << instruction[i];
	}
	std::cout << std::endl;
}

// Prints "invalid register" error
void Processor::errInvalidRegister(const std::string &strReg)
{
	std::cout << "Ivalid register: " << strReg << std::endl;
}

// Prints "invalid operand" error
void Processor::errInvalidOperand(const std::string &strOperand)
{
	std::cout << "Ivalid operand: " << strOperand << std::endl;
}

// Returns register index from string
int Processor::getRegIndex(const std::string &strReg)
{
	if (strReg[0] == 'I' || strReg[0] == 'L')
	{
		std::istringstream iss(strReg.substr(1));
		int regIndex = 0;
		if (iss >> regIndex &&regIndex >= 0 && regIndex < REG_WIDTH)
			return regIndex;
	}

	return -1;
}

// Finds a register (signed int) by string and returns a pointer to it
bool Processor::getRegInt(const std::string &strReg, signed int *&pReg)
{
	int regIndex = getRegIndex(strReg);
	pReg = &m_regInt[regIndex];
	return (regIndex >= 0);
}

// Finds a register (unsigned long) by string and returns a pointer to it
bool Processor::getRegLong(const std::string &strReg, unsigned long *&pReg)
{
	int regIndex = getRegIndex(strReg);
	pReg = &m_regLong[regIndex];
	return (regIndex >= 0);
}

// Resets all processor variables
void Processor::resetProcessor(void)
{
	for (unsigned i = 0; i < REG_WIDTH; i++)
	{
		m_regInt[i] = 0;
		m_regLong[i] = 0;
	}

	m_program.clear();
	m_programCounter = 0;
	m_stack.clear();

	m_flagCarry = false;
	m_flagBorrow = false;
}
