#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> strSplit(const std::string& strInput, const char separator = ' ', const bool removeEmpty = false);
bool strBeginsWith(const std::string& str, const std::string& beginning);
bool strSIntTryParse(const std::string& strIn, signed int& iOut);
bool strULongTryParse(const std::string& strIn, unsigned long& uOut);
std::string strToUpper(const std::string& strInput);

std::string SIntToString(const signed int& input, const unsigned& base);
std::string ULongToString(const unsigned long& input, const unsigned& base);

void errMessage(const std::string& msg);
void errInvalidInstruction(const std::vector<std::string>& instruction);
void errInvalidRegister(const std::string& strReg);
void errInvalidOperand(const std::string& strOperand);
