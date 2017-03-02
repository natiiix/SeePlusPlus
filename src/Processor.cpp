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
	{
		errMessage("Could not open program file!");
		return false;
	}

	std::string strInstruction;
	while (std::getline(file, strInstruction))
	{
		unsigned instrLen = strInstruction.size();

		// Ignore empty lines
		if (instrLen > 0 &&
			// Ignore commented out lines
			!strBeginsWith(strInstruction, "#") &&
			!strBeginsWith(strInstruction, ";") &&
			!strBeginsWith(strInstruction, "//"))
		{
			// Push the label into the label vectors
			if (strInstruction[instrLen - 1] == ':')
			{
				m_labelsAddr.push_back(m_instr.size());
				m_labelsStr.push_back(strInstruction.substr(0, instrLen - 1));
			}
			else
				// Push the instruction into program memory
				m_instr.push_back(strSplit(strInstruction, ' ', true));
		}
	}

	file.close();
	return true;
}

bool Processor::ExecuteProgram(void)
{
	try
	{
		while (m_programCounter < m_instr.size())
		{
			ExecuteInstruction(m_instr[m_programCounter++]);
		}
	}
	catch (...)
	{
		errMessage("Program runtime error occurred! Program counter: " + std::to_string(m_programCounter));
		return false;
	}

	return true;
}

// Executes an instruction
bool Processor::ExecuteInstruction(const std::vector<std::string> &instruction)
{
	if (instruction.size() <= 0)
		return false;

	std::string opcode = strToUpper(instruction[0]);

	// Custom instructions
	if (opcode == "DUMP" && instruction.size() == 2) return instrDUMP(instruction[1]);
	if (opcode == "DUMPB" && instruction.size() == 2) return instrDUMPB(instruction[1]);
	if (opcode == "DUMPH" && instruction.size() == 2) return instrDUMPH(instruction[1]);

	// x86 instrunctions
	if (opcode == "MOV" && instruction.size() == 3) return instrMOV(instruction[1], instruction[2]);
	// Math
	if (opcode == "INC" && instruction.size() == 2) return instrINC(instruction[1]);
	if (opcode == "DEC" && instruction.size() == 2) return instrDEC(instruction[1]);
	if (opcode == "ADD" && instruction.size() == 3) return instrADD(instruction[1], instruction[2]);
	if (opcode == "ADC" && instruction.size() == 2) return instrADC(instruction[1]);
	if (opcode == "ADC" && instruction.size() == 3) return instrADC(instruction[1], instruction[2]);
	if (opcode == "SUB" && instruction.size() == 3) return instrSUB(instruction[1], instruction[2]);
	if (opcode == "SBB" && instruction.size() == 2) return instrSBB(instruction[1]);
	if (opcode == "SBB" && instruction.size() == 3) return instrSBB(instruction[1], instruction[2]);
	if (opcode == "MUL" && instruction.size() == 3) return instrMUL(instruction[1], instruction[2]);
	if (opcode == "DIV" && instruction.size() == 3) return instrDIV(instruction[1], instruction[2]);
	if (opcode == "MOD" && instruction.size() == 3) return instrMOD(instruction[1], instruction[2]);
	if (opcode == "CMP" && instruction.size() == 3) return instrCMP(instruction[1], instruction[2]);
	// Jump
	if (opcode == "JMP" && instruction.size() == 2) return instrJMP(instruction[1]);
	if (opcode == "JZ" && instruction.size() == 2) return instrJZ(instruction[1]);
	if (opcode == "JNZ" && instruction.size() == 2) return instrJNZ(instruction[1]);
	if (opcode == "JG" && instruction.size() == 2) return instrJG(instruction[1]);
	if (opcode == "JGE" && instruction.size() == 2) return instrJGE(instruction[1]);
	if (opcode == "JL" && instruction.size() == 2) return instrJL(instruction[1]);
	if (opcode == "JLE" && instruction.size() == 2) return instrJLE(instruction[1]);
	// Call
	if (opcode == "CALL" && instruction.size() == 2) return instrCALL(instruction[1]);
	if (opcode == "RET" && instruction.size() == 1) return instrRET();
	if (opcode == "CZ" && instruction.size() == 2) return instrCZ(instruction[1]);
	if (opcode == "CNZ" && instruction.size() == 2) return instrCNZ(instruction[1]);
	if (opcode == "CG" && instruction.size() == 2) return instrCG(instruction[1]);
	if (opcode == "CGE" && instruction.size() == 2) return instrCGE(instruction[1]);
	if (opcode == "CL" && instruction.size() == 2) return instrCL(instruction[1]);
	if (opcode == "CLE" && instruction.size() == 2) return instrCLE(instruction[1]);

	// Unrecognized instruction
	errInvalidInstruction(instruction);

	return false;
}

// Resets all processor variables
void Processor::resetProcessor(void)
{
	for (unsigned i = 0; i < REG_WIDTH; i++)
	{
		m_regInt[i] = 0;
		m_regLong[i] = 0;
	}

	m_flagCarry = false;
	m_flagBorrow = false;
	m_flagZero = false;

	m_programCounter = 0;
	m_instr.clear();
	m_stack.clear();
	m_labelsAddr.clear();
	m_labelsStr.clear();
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
