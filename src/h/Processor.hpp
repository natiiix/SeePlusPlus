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
	bool ExecuteInstruction(const std::vector<std::string> &instruction);

private:
	static const int REG_WIDTH = 8;
	signed int m_regInt[REG_WIDTH];
	unsigned long m_regLong[REG_WIDTH];
	std::vector<std::string> m_program;
	unsigned m_programCounter;
	std::vector<unsigned> m_stack;
	bool m_flagCarry;
	bool m_flagBorrow;

	void errMessage(const std::string &msg);
	void errInvalidInstruction(const std::vector<std::string> &instruction);
	void errInvalidRegister(const std::string &strReg);
	void errInvalidOperand(const std::string &strOperand);

	int getRegIndex(const std::string &strReg);
	bool getRegInt(const std::string &strReg, signed int *&pReg);
	bool getRegLong(const std::string &strReg, unsigned long *&pReg);

	void resetProcessor(void);

	// Custom instructions
	bool instrDUMP(const std::string &strReg); // Prints the register to console

	// x86 instructions
	bool instrMOV(const std::string &strDest, const std::string &strSource); // Move
	bool instrINC(const std::string &strDest); // Increment by 1
	bool instrDEC(const std::string &strDest); // Decrement by 1
	bool instrADD(const std::string &strDest, const std::string &strSource); // Add
	bool instrADC(const std::string &strDest); // Add carry
	bool instrADC(const std::string &strDest, const std::string &strSource); // Add with carry
	bool instrSUB(const std::string &strDest, const std::string &strSource); // Subtract
	bool instrSBB(const std::string &strDest); // Subtract borrow
	bool instrSBB(const std::string &strDest, const std::string &strSource); // Subtract with borrow
};