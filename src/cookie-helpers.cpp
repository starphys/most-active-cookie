#include "cookie-helpers.hpp"

int parseCommandLineInput(int args, char **argv, std::string *fileForInput, std::string *dateOfCookies)
{
    CLI::App app;
    bool date_flag{false};

    app.add_option("file", *fileForInput, "Only accepts .csv files at this time")->required();
    CLI::Option *dOption = app.add_flag("-d", date_flag, "Flag followed by a date");
    app.add_option("date", *dateOfCookies, "Date following -d")->needs(dOption);

    CLI11_PARSE(app, args, argv);

    return 0;
}