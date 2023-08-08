#include <string>

using namespace std;

std::string exclaim(std::string& input)
{
    std::string out = input;

    for (auto& ch : out)
    {
        if (ispunct(ch))
        {
            ch = '!';
        }
    }

    return out;
}