#include "cookie-helpers.hpp"

bool parseCommandLineInput(int args, char **argv, std::string *fileForInput, std::string *dateOfCookies)
{
    CLI::App app;
    bool date_flag{false};

    app.add_option("file", *fileForInput, "Only accepts .csv files at this time")->required();
    CLI::Option *dOption = app.add_flag("-d", date_flag, "Flag followed by a date");
    app.add_option("date", *dateOfCookies, "Date following -d")->needs(dOption);

    CLI11_PARSE(app, args, argv);

    // Expect a .csv file for the first command
    if (fileForInput->substr(fileForInput->length() - 4, fileForInput->length()) != ".csv")
    {
        std::cout << "This tool only works on .csv files, please enter a .csv file as the first argument" << std::endl;
        return false;
    }

    return true;
}