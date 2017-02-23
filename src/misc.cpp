#include "h/misc.hpp"

std::vector<std::string> split(const std::string &strInput, const char separator, const bool removeEmpty)
{
    std::vector<std::string> strings;
    std::istringstream strstream(strInput);

    std::string sTemp;
    while (getline(strstream, sTemp, separator))
    {
        if (!removeEmpty || sTemp.length() > 0)
        {
            strings.push_back(sTemp);
        }
    }

    return strings;
}

bool strBeginsWith(const std::string & str, const std::string & beginning)
{
    for (int i = 0; i < (int)beginning.size(); i++)
    {
        if (str[i] != beginning[i])
            return false;
    }

    return true;
}

bool strSIntTryParse(const std::string & strIn, signed int & iOut)
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
            char digitASCII = strValue[strValueLen - i - 1];
            signed int digitValue = 0;

            if (digitASCII >= 48 /* '0' */ && digitASCII <= 49 /* '1' */)
                digitValue = digitASCII - 48;
            else
                return false;

            val += digitValue * (signed int)pow(2.0f, i);
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
            char digitASCII = strValue[strValueLen - i - 1];
            signed int digitValue = 0;

            if (digitASCII >= 48 /* '0' */ && digitASCII <= 57 /* '9' */)
                digitValue = digitASCII - 48;
            else if (digitASCII >= 65 /* 'A' */ && digitASCII <= 70 /* 'F' */)
                digitValue = digitASCII - 65 + 10;
            else if (digitASCII >= 97 /* 'a' */ && digitASCII <= 102 /* 'f' */)
                digitValue = digitASCII - 97 + 10;
            else
                return false;

            val += digitValue * (signed int)pow(16.0f, i);
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

bool strULongTryParse(const std::string & strIn, unsigned long & uOut)
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
            char digitASCII = strValue[strValueLen - i - 1];
            unsigned long digitValue = 0;

            if (digitASCII >= 48 /* '0' */ && digitASCII <= 49 /* '1' */)
                digitValue = digitASCII - 48;
            else
                return false;

            val += digitValue * (unsigned long)pow(2.0f, i);
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
            char digitASCII = strValue[strValueLen - i - 1];
            unsigned long digitValue = 0;

            if (digitASCII >= 48 /* '0' */ && digitASCII <= 57 /* '9' */)
                digitValue = digitASCII - 48;
            else if (digitASCII >= 65 /* 'A' */ && digitASCII <= 70 /* 'F' */)
                digitValue = digitASCII - 65 + 10;
            else if (digitASCII >= 97 /* 'a' */ && digitASCII <= 102 /* 'f' */)
                digitValue = digitASCII - 97 + 10;
            else
                return false;

            val += digitValue * (unsigned long)pow(16.0f, i);
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