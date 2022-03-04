#include <iostream>
#include <fstream>
#include "CLI11.hpp"
#include "CookieMap.hpp"

int main(int args, char **argv)
{
    CookieMap cookieMap{};
    std::string fileFromCLI{}, dateFromCLI{};
    CLI::App app;
    bool date_flag{false};

    // Parse command line input, requiring at least some string is specified. Will confirm that string is a .csv
    app.add_option("file", fileFromCLI, "Only accepts .csv files at this time")->required();
    CLI::Option *dOption = app.add_flag("-d", date_flag, "Flag followed by a date");
    app.add_option("date", dateFromCLI, "Date following -d")->needs(dOption)->required();

    CLI11_PARSE(app, args, argv);

    // Validate file string
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
