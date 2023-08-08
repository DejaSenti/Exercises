#include <iostream>
#include <string>

#include "url.hpp"
#include "exclaim.hpp"

using namespace std;

void TestClassesAndStrings()
{
    URL url("http", "udemy.com");

    url.Display();
}

void TestCharFunctions()
{
    std::string str = "hi there, would you like to sign my petition?";

    std::string exclaimed_str = exclaim(str);

    std::cout << exclaimed_str;
}

int main()
{
    TestClassesAndStrings();

    TestCharFunctions();

    return 0;
}