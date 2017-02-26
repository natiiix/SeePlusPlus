#include "h/Processor.hpp"

bool Processor::instrMOV(const std::string &strDest, const std::string &strSource)
{
	// Destination register is int
	if (strDest[0] == 'I')
	{
		signed int *pRegDest = nullptr;
		if (getRegInt(strDest, pRegDest))
		{
			// Source register is int
			if (strSource[0] == 'I')
			{
				signed int *pRegSource = nullptr;
				if (getRegInt(strSource, pRegSource))
				{
					*pRegDest = *pRegSource;
					return true;
				}

				errInvalidRegister(strSource);
				return false;
			}
			// Source register is long
			else if (strSource[0] == 'L')
			{
				unsigned long *pRegSource = nullptr;
				if (getRegLong(strSource, pRegSource))
				{
					*pRegDest = (signed int)*pRegSource;
					return true;
				}

				errInvalidRegister(strSource);
				return false;
			}
			// Source is a literal value
			else if (strSIntTryParse(strSource, *pRegDest))
				return true;

			errInvalidOperand(strSource);
			return false;
		}
	}
	// Destination register is long
	else if (strDest[0] == 'L')
	{
		unsigned long *pRegDest = nullptr;
		if (getRegLong(strDest, pRegDest))
		{
			// Source register is int
			if (strSource[0] == 'I')
			{
				signed int *pRegSource = nullptr;
				if (getRegInt(strSource, pRegSource))
				{
					*pRegDest = (unsigned long)*pRegSource;
					return true;
				}

				errInvalidRegister(strSource);
				return false;
			}
			// Source register is long
			else if (strSource[0] == 'L')
			{
				unsigned long *pRegSource = nullptr;
				if (getRegLong(strSource, pRegSource))
				{
					*pRegDest = *pRegSource;
					return true;
				}

				errInvalidRegister(strSource);
				return false;
			}
			// Source is a literal value
			else if (strULongTryParse(strSource, *pRegDest))
				return true;

			errInvalidOperand(strSource);
			return false;
		}
	}

	errInvalidRegister(strDest);
	return false;
}
