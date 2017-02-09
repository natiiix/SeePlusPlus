#include <iostream>
#include <string>
#include <vector>

class Processor
{
public:
  Processor();
  bool Execute(const std::vector<std::string> &command);

private:
  static const int REG_WIDTH = 8;
  signed int regInt[REG_WIDTH];
  unsigned long regLong[REG_WIDTH];

  void errInvalidRegister(const std::string &strReg);
  void errInvalidOperand(const std::string &strOperand);

  int getRegIndex(const std::string &strReg);
  bool getRegInt(const std::string &strReg, signed int *&pReg);
  bool getRegLong(const std::string &strReg, unsigned long *&pReg);

  // Custom instructions
  bool instrDUMP(const std::string &strReg); // Prints the register to console

  // x86 instructions
  bool instrMOV(const std::string &strDest, const std::string &strSource);
};