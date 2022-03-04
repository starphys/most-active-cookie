#include <iostream>
#include "cookie-helpers.hpp"
#include "CookieMap.hpp"

int main(int args, char **argv)
{
    // Parse command line input, requiring at least some string is specified. Will confirm that string is a .csv
    CookieMap cookieMap{};
    std::string fileFromCLI{}, dateFromCLI{};
    parseCommandLineInput(args, argv, &fileFromCLI, &dateFromCLI);

    // Validate file string
    if (fileFromCLI.empty())
    {
        std::cout << "File name required, run with --help for more information." << std::endl;
        return -1;
    }
    if (fileFromCLI.substr(fileFromCLI.length() - 4, fileFromCLI.length()) != ".csv")
    {
        std::cout << "This tool only works on .csv files, please enter a .csv file as the first argument" << std::endl;
        return -1;
    }

    // Validate date string
    if (dateFromCLI.empty())
    {
        std::cout << "Date required at this time, run with --help for more information." << std::endl;
        return -1;
    }

    // Attempt to open file
    std::ifstream fin;
    fin.open(fileFromCLI, std::fstream::in);
    if (!fin)
    {
        std::cout << "File could not be opened." << std::endl;
        return -1;
    }

    // Populate map with cookies from file on date
    cookieMap.loadCookies(fin, dateFromCLI);

    // Print most active cookie from date to command line
    cookieMap.printMostActiveCookies(std::cout);

    return 0;
}
