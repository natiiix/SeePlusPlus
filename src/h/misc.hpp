#pragma once

#include <sstream>
#include <string>
#include <vector>
#include <cmath>

std::vector<std::string> split(const std::string &strInput, const char separator, const bool removeEmpty = false);
bool strBeginsWith(const std::string & str, const std::string & beginning);
bool strSIntTryParse(const std::string & strIn, signed int & iOut);
bool strULongTryParse(const std::string & strIn, unsigned long & uOut);