#include "h/misc.hpp"

// Splits string by a separator character and returns a vector of partial strings
std::vector<std::string> strSplit(const std::string &strInput, const char separator, const bool removeEmpty)
{
	std::vector<std::string> strings;
	std::istringstream strstream(strInput);

	std::string sTemp;
	while (getline(strstream, sTemp, separator))
	{
		if (!removeEmpty || sTemp.size() > 0)
		{
			strings.push_back(sTemp);
		}
	}

	return strings;
}

// Returns true if string str begins with string beginning, false otherwise
bool strBeginsWith(const std::string &str, const std::string &beginning)
{
	for (int i = 0; i < (int)beginning.size(); i++)
	{
		if (str[i] != beginning[i])
			return false;
	}

	return true;
}

// Parses signed int from a string, accepts DEC, BIN, HEX
bool strSIntTryParse(const std::string &strIn, signed int &iOut)
{
	bool negativeVal = (strIn[0] == '-');
	std::string strPrefix = strIn.substr((negativeVal ? 1 : 0), 2);

	if (strPrefix == "0b")
	{
		signed int val = 0;
		std::string strValue = strIn.substr((negativeVal ? 3 : 2));
		unsigned strValueLen = strValue.size();

		for (unsigned i = 0; i < strValueLen; i++)
		{
			char digitASCII = strValue[i];
			signed int digitValue = 0;

			if (digitASCII >= '0' &&digitASCII <= '1')
				digitValue = digitASCII - '0';
			else
				return false;

			val <<= 1;
			val |= digitValue;
		}

		iOut = (negativeVal ? -val : val);

		return true;
	}
	else if (strPrefix == "0x")
	{
		signed int val = 0;
		std::string strValue = strIn.substr((negativeVal ? 3 : 2));
		unsigned strValueLen = strValue.size();

		for (unsigned i = 0; i < strValueLen; i++)
		{
			char digitASCII = strValue[i];
			signed int digitValue = 0;

			if (digitASCII >= '0' &&digitASCII <= '9')
				digitValue = digitASCII - '0';
			else if (digitASCII >= 'A' &&digitASCII <= 'F')
				digitValue = digitASCII - 'A' + 10;
			else if (digitASCII >= 'a' &&digitASCII <= 'f')
				digitValue = digitASCII - 'a' + 10;
			else
				return false;

			val <<= 4;
			val |= digitValue;
		}

		iOut = (negativeVal ? -val : val);

		return true;
	}
	else
	{
		std::istringstream iss(strIn);
		signed int val = 0;

		if (iss >> val)
		{
			iOut = val;
			return true;
		}

		return false;
	}
}

// Parses unsigned long from a string, accepts DEC, BIN, HEX
bool strULongTryParse(const std::string &strIn, unsigned long &uOut)
{
	bool negativeVal = (strIn[0] == '-');
	std::string strPrefix = strIn.substr((negativeVal ? 1 : 0), 2);

	if (strPrefix == "0b")
	{
		unsigned long val = 0;
		std::string strValue = strIn.substr((negativeVal ? 3 : 2));
		unsigned strValueLen = strValue.size();

		for (unsigned i = 0; i < strValueLen; i++)
		{
			char digitASCII = strValue[i];
			unsigned long digitValue = 0;

			if (digitASCII >= '0' &&digitASCII <= '1')
				digitValue = digitASCII - '0';
			else
				return false;

			val <<= 1;
			val |= digitValue;
		}

		uOut = (negativeVal ? -val : val);

		return true;
	}
	else if (strPrefix == "0x")
	{
		unsigned long val = 0;
		std::string strValue = strIn.substr((negativeVal ? 3 : 2));
		unsigned strValueLen = strValue.size();

		for (unsigned i = 0; i < strValueLen; i++)
		{
			char digitASCII = strValue[i];
			unsigned long digitValue = 0;

			if (digitASCII >= '0' &&digitASCII <= '9')
				digitValue = digitASCII - '0';
			else if (digitASCII >= 'A' &&digitASCII <= 'F')
				digitValue = digitASCII - 'A' + 10;
			else if (digitASCII >= 'a' &&digitASCII <= 'f')
				digitValue = digitASCII - 'a' + 10;
			else
				return false;

			val <<= 4;
			val |= digitValue;
		}

		uOut = (negativeVal ? -val : val);

		return true;
	}
	else
	{
		std::istringstream iss(strIn);
		unsigned long val = 0;

		if (iss >> val)
		{
			uOut = val;
			return true;
		}

		return false;
	}
}

// Converts a string to uppercase
std::string strToUpper(const std::string &strInput)
{
	std::string strUpper;

	for (unsigned i = 0; i < strInput.size(); i++)
	{
		if (strInput[i] >= 'a' &&strInput[i] <= 'z')
			strUpper.push_back(strInput[i] + ('A' - 'a'));
		else
			strUpper.push_back(strInput[i]);
	}

	return strUpper;
}

// Converts a signed integer to string representation of its value in a specified base
std::string SIntToString(const signed int &input, const unsigned &base)
{
	std::string strOut;
	bool negative = (input < 0);
	signed int remainder = (negative ? -input : input);
	std::vector<signed int> digits;

	// Solve negative number
	if (negative)
		strOut.push_back('-');

	switch (base)
	{
		// BIN
	case 2:
		strOut.push_back('0');
		strOut.push_back('b');
		break;

		// DEC
	case 10:
		break;

		// HEX
	case 16:
		strOut.push_back('0');
		strOut.push_back('x');
		break;

		// Invalid base
	default:
		return std::string();
	}

	// Separate digits
	do
	{
		digits.push_back(remainder % base);
		remainder /= base;
	} while (remainder > 0);

	// Write digits into the output string as characters
	while (digits.size() > 0)
	{
		char cDigit = digits.back();

		if (cDigit >= 0 && cDigit <= 9)
			cDigit += '0';
		else if (cDigit >= 10 && cDigit <= 15)
			cDigit += 'A' - 10;

		strOut.push_back(cDigit);
		digits.pop_back();
	}

	return strOut;
}

// Converts an unsigned long to string representation of its value in a specified base
std::string ULongToString(const unsigned long &input, const unsigned &base)
{
	std::string strOut;
	unsigned long remainder = input;
	std::vector<unsigned long> digits;

	switch (base)
	{
		// BIN
	case 2:
		strOut.push_back('0');
		strOut.push_back('b');
		break;

		// DEC
	case 10:
		break;

		// HEX
	case 16:
		strOut.push_back('0');
		strOut.push_back('x');
		break;

		// Invalid base
	default:
		return std::string();
	}

	// Separate digits
	do
	{
		digits.push_back(remainder % base);
		remainder /= base;
	} while (remainder > 0);

	// Write digits into the output string as characters
	while (digits.size() > 0)
	{
		char cDigit = digits.back();

		if (cDigit >= 0 && cDigit <= 9)
			cDigit += '0';
		else if (cDigit >= 10 && cDigit <= 15)
			cDigit += 'A' - 10;

		strOut.push_back(cDigit);
		digits.pop_back();
	}

	return strOut;
}

// Prints a message representing the recently occurred exception
void errMessage(const std::string &msg)
{
	std::cout << "Error occurred: " << msg << std::endl;
}

// Prints "invalid instruction" error
void errInvalidInstruction(const std::vector<std::string> &instruction)
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
void errInvalidRegister(const std::string &strReg)
{
	std::cout << "Ivalid register: " << strReg << std::endl;
}

// Prints "invalid operand" error
void errInvalidOperand(const std::string &strOperand)
{
	std::cout << "Ivalid operand: " << strOperand << std::endl;
}
