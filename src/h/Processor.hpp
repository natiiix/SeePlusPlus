#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

#include "misc.hpp"

class Processor
{
public:
	Processor(void);
	bool LoadProgram(const std::string &filepath);
	bool ExecuteProgram(void);

private:
	static const int REG_WIDTH = 8;
	signed int m_regInt[REG_WIDTH];
	unsigned long m_regLong[REG_WIDTH];
	bool m_flagCarry;
	bool m_flagBorrow;
	bool m_flagZero;
	unsigned m_programCounter;
	std::vector<std::vector<std::string>> m_instr;
	std::vector<unsigned> m_stack;
	std::vector<unsigned> m_labelsAddr;
	std::vector<std::string> m_labelsStr;

	void resetProcessor(void);
	bool ExecuteInstruction(const std::vector<std::string> &instruction);

	int getRegIndex(const std::string &strReg);
	bool getRegInt(const std::string &strReg, signed int *&pReg);
	bool getRegLong(const std::string &strReg, unsigned long *&pReg);

	// Custom instructions
	bool instrDUMP(const std::string &strReg); // Prints the register to console

	// x86 instructions
	bool instrMOV(const std::string &strDest, const std::string &strSource); // Move
	bool instrINC(const std::string &strDest); // Increment by 1
	bool instrDEC(const std::string &strDest); // Decrement by 1
	bool instrADD(const std::string &strDest, const std::string &strSource); // Add
	bool instrADC(const std::string &strDest); // Add 1 if carry flag is set
	bool instrADC(const std::string &strDest, const std::string &strSource); // Add with carry
	bool instrSUB(const std::string &strDest, const std::string &strSource); // Subtract
	bool instrSBB(const std::string &strDest); // Subtract 1 if borrow flag is set
	bool instrSBB(const std::string &strDest, const std::string &strSource); // Subtract with borrow
	bool instrCALL(const std::string &strDest); // Call subroutine
	bool instrRET(void); // Return from subroutine
	bool instrCMP(const std::string &strDest, const std::string &strSource); // Compare operands
	bool instrJMP(const std::string &strDest); // Unconditional jump
	bool instrJZ(const std::string &strDest); // Jump if zero flag is set
	bool instrJNZ(const std::string &strDest); // Jump if zero flag is not set
};
