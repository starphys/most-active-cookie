#pragma once
#include <unordered_map>
#include <fstream>
#include <string>

class CookieMap
{
private:
    std::unordered_map<std::string, int> cookiesFromDate;
    int highestFrequency;

    bool extractCookieString(std::string input, std::string *cookie, std::string date);

public:
    CookieMap();
    ~CookieMap();

    void loadCookies(std::ifstream &inputFile, std::string date);
    void printMostActiveCookies(std::ostream &os);
    void printAllCookies(std::ostream &os);
};