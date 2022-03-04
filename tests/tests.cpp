#include <gtest/gtest.h>
#include "../src/cookie-helpers.hpp"
#include "../src/CookieMap.hpp"

// Test Suite: Correct output
TEST(TestOutput, December92018)
{
    CookieMap cookieMap{};
    std::string fileFromCLI{"../cookie-log.csv"}, dateFromCLI{"2018-12-09"};

    std::ifstream fin;
    fin.open(fileFromCLI, std::fstream::in);

    ASSERT_TRUE(fin);

    cookieMap.loadCookies(fin, dateFromCLI);

    testing::internal::CaptureStdout();

    cookieMap.printMostActiveCookies(std::cout);

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "AtY0laUfhglK3lC7\n");
}

TEST(TestOutput, December82018)
{
    CookieMap cookieMap{};
    std::string fileFromCLI{"../cookie-log.csv"}, dateFromCLI{"2018-12-08"};

    std::ifstream fin;
    fin.open(fileFromCLI, std::fstream::in);

    ASSERT_TRUE(fin);

    cookieMap.loadCookies(fin, dateFromCLI);

    testing::internal::CaptureStdout();

    cookieMap.printMostActiveCookies(std::cout);

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "fbcn5UAVanZf6UtG\n4sMM2LxV07bPJzwf\nSAZuXPGUrfbcn5UA\n");
}

TEST(TestOutput, December72018)
{
    CookieMap cookieMap{};
    std::string fileFromCLI{"../cookie-log.csv"}, dateFromCLI{"2018-12-07"};

    std::ifstream fin;
    fin.open(fileFromCLI, std::fstream::in);

    ASSERT_TRUE(fin);

    cookieMap.loadCookies(fin, dateFromCLI);

    testing::internal::CaptureStdout();

    cookieMap.printMostActiveCookies(std::cout);

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "4sMM2LxV07bPJzwf\n");
}

TEST(TestOutput, EmptyLog)
{
    CookieMap cookieMap{};
    std::string fileFromCLI{"../empty-log.csv"}, dateFromCLI{"2018-12-07"};

    std::ifstream fin;
    fin.open(fileFromCLI, std::fstream::in);

    ASSERT_TRUE(fin);

    cookieMap.loadCookies(fin, dateFromCLI);

    testing::internal::CaptureStdout();

    cookieMap.printMostActiveCookies(std::cout);

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.empty());
}

TEST(TestOutput, BadLog)
{
    CookieMap cookieMap{};
    std::string fileFromCLI{"../bad-log.csv"}, dateFromCLI{"2018-12-07"};

    std::ifstream fin;
    fin.open(fileFromCLI, std::fstream::in);

    ASSERT_TRUE(fin);

    cookieMap.loadCookies(fin, dateFromCLI);

    testing::internal::CaptureStdout();

    cookieMap.printMostActiveCookies(std::cout);

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.empty());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}