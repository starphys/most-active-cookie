#include <unordered_map>
#include <fstream>

std::unordered_map<std::string, int> *getCookiesFromDate(std::fstream &inputFile, std::string date);
bool getCookieFromStringByDate(std::string input, std::string *cookie, std::string date);
