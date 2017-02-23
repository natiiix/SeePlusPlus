#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "misc.hpp"

class Processor
{
public:
  Processor();
  bool Execute(const std::vector<std::string> &command);

private:
  static const int REG_WIDTH = 8;
  signed int regInt[REG_WIDTH];
  unsigned long regLong[REG_WIDTH];
  bool flagCarry;
  bool flagBorrow;

  void errInvalidRegister(const std::string &strReg);
  void errInvalidOperand(const std::string &strOperand);

  int getRegIndex(const std::string &strReg);
  bool getRegInt(const std::string &strReg, signed int *&pReg);
  bool getRegLong(const std::string &strReg, unsigned long *&pReg);
  
  void clearFlags();

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