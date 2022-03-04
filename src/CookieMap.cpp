#include "CookieMap.hpp"

CookieMap::CookieMap() : cookiesFromDate{}, highestFrequency{1} {}
CookieMap::~CookieMap() {}

// Extracts cookie from a log line, stores it in a string and returns success or failure
bool CookieMap::extractCookieString(std::string input, std::string *cookie, std::string date)
{
    auto commaIndex = input.find_first_of(',');
    auto timeIndex = input.find_first_of('T', commaIndex);

    if (commaIndex == std::string::npos || commaIndex == std::string::npos)
    {
        return false;
    }

    if (input.substr(commaIndex + 1, (timeIndex - commaIndex - 1)) == date)
    {
        *cookie = input.substr(0, commaIndex);
        return true;
    }

    return false;
}

// Add cookies from specified file on specified date to a map with their frequency
void CookieMap::loadCookies(std::ifstream &inputFile, std::string date)
{
    std::string line{}, cookie{};

    // Read through the file, storing cookies appropriately
    while (true)
    {
        if (inputFile.eof())
        {
            break;
        }
        std::getline(inputFile, line);

        // If current line has a matching date string, include the cookie in the map
        if (extractCookieString(line, &cookie, date))
        {
            // If cookie is present in map, increment value. Otherwise, add cookie
            std::unordered_map<std::string, int>::iterator cookieIt = cookiesFromDate.find(cookie);
            if (cookieIt != cookiesFromDate.end())
            {
                cookieIt->second++;
                if (cookieIt->second > highestFrequency)
                {
                    highestFrequency = cookieIt->second;
                }
            }
            else
            {
                cookiesFromDate.insert(std::make_pair(cookie, 1));
            }
        }
    }
}

// Print all cookies that match highest value
void CookieMap::printMostActiveCookies(std::ostream &os)
{
    for (std::unordered_map<std::string, int>::iterator cookieIt = cookiesFromDate.begin(); cookieIt != cookiesFromDate.end(); ++cookieIt)
    {
        if (cookieIt->second == highestFrequency)
        {
            os << cookieIt->first << '\n';
        }
    }
}

// Print entire map
void CookieMap::printAllCookies(std::ostream &os)
{
    for (std::unordered_map<std::string, int>::iterator cookieIt = cookiesFromDate.begin(); cookieIt != cookiesFromDate.end(); ++cookieIt)
    {

        os << cookieIt->first << " " << cookieIt->second << '\n';
    }
}
