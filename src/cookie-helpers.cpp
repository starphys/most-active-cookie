#include "cookie-helpers.hpp"

// Assume passed in values have been validated
std::unordered_map<std::string, int> *getCookiesFromDate(std::fstream &inputFile, std::string date)
{

    // Edge cases left to handle:
    //  Check for empty files, single values, any other edge cases we can find
    //  Check if given date is after first line or before last line
    //  Are there other things to check for, like bad data? If the data is bad, should we just reject all of it?

    std::unordered_map<std::string, int> *cookieMap = new std::unordered_map<std::string, int>;
    std::string line{}, cookie{};

    // Read through the file, storing cookies appropriately
    while (true)
    {
        if (inputFile.eof())
        {
            break;
        }
        std::getline(inputFile, line);

        // If current line has a matching date flag, include the cookie in the map
        if (getCookieFromStringByDate(line, &cookie, date))
        {
            // If cookie is present in map, increment value. Otherwise, add cookie
            std::unordered_map<std::string, int>::iterator cookieIt = cookieMap->find(cookie);
            if (cookieIt != cookieMap->end())
            {
                cookieIt->second++;
            }
            else
            {
                cookieMap->insert(std::make_pair(cookie, 1));
            }
        }
    }

    return cookieMap;
}

bool getCookieFromStringByDate(std::string input, std::string *cookie, std::string date)
{
    // Edge cases left to handle:
    // commaIndex, timeIndex not found
    auto commaIndex = input.find_first_of(',');
    auto timeIndex = input.find_first_of('T', commaIndex);

    if (input.substr(commaIndex + 1, (timeIndex - commaIndex - 1)) == date)
    {
        *cookie = input.substr(0, commaIndex);
        return true;
    }

    return false;
}