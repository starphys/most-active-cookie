#include <iostream>
#include "cookie-helpers.hpp"
#include "CLI11.hpp"

int main(int args, char **argv)
{
    // Parse command line input, requiring at least some string is specified. Will confirm that string is a .csv
    CLI::App app;

    bool date_flag{false};
    std::string fileFromCLI{}, dateFromCLI{};

    app.add_option("file", fileFromCLI, "Only accepts .csv files at this time")->required();
    CLI::Option *dOption = app.add_flag("-d", date_flag, "Flag followed by a date");
    app.add_option("date", dateFromCLI, "Date following -d")->needs(dOption);

    CLI11_PARSE(app, args, argv);

    // Expect a file for the first command
    // TODO: is hardcoding all of this the best way to do this?
    if (fileFromCLI.substr(fileFromCLI.length() - 4, fileFromCLI.length()) != ".csv")
    {
        std::cout << "This tool only works on .csv files, please enter a .csv file as the first argument" << std::endl;
        return 0;
    }

    // TODO: Validate date format
    // Will also need to check if date is within range from .csv

    // Attempt to open file
    std::fstream fin;
    fin.open(fileFromCLI, std::fstream::in);
    if (!fin)
    {
        std::cout << "File could not be opened." << std::endl;
        return 0;
    }

    // Create map of cookies from the given date with their frequencies
    std::unordered_map<std::string, int> *cookieMap = getCookiesFromDate(fin, dateFromCLI);

    // Find highest value
    int highestCount{0};
    for (std::unordered_map<std::string, int>::iterator cookieIt = cookieMap->begin(); cookieIt != cookieMap->end(); ++cookieIt)
    {
        if (cookieIt->second > highestCount)
        {
            highestCount = cookieIt->second;
        }
    }

    // Print all cookies that match highest value
    for (std::unordered_map<std::string, int>::iterator cookieIt = cookieMap->begin(); cookieIt != cookieMap->end(); ++cookieIt)
    {
        if (cookieIt->second == highestCount)
        {
            std::cout << cookieIt->first << '\n';
        }
    }

    return 0;
}
