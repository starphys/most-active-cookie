#include <iostream>
#include "cookie-helpers.hpp"
#include "CookieMap.hpp"

int main(int args, char **argv)
{
    // TODO: edge cases:
    // Listed inline, also how to handle if date is empty? require date?
    // Try/catch for bad file data
    // TODO: Validate date format
    // Will also need to check if date is within range from .csv

    // Parse command line input, requiring at least some string is specified. Will confirm that string is a .csv
    CookieMap cookieMap{};
    std::string fileFromCLI{}, dateFromCLI{};
    if (!parseCommandLineInput(args, argv, &fileFromCLI, &dateFromCLI))
    {
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
