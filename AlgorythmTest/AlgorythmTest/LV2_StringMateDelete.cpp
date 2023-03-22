#include <iostream>
#include<string>
using namespace std;

int solution(string s)
{
    int charCount[26]{};
    char prevChar{ ' ' };
    string str{ s };
    string newStr{ "" };
    bool deletedString{ false };
    while (true)
    {
        deletedString = false;
        for (size_t i{ 0 }; i < str.length(); ++i)
        {
            if (str[i] == str[i + 1])
            {
                ++i;
                deletedString = true;
                continue;
            }
            else
            {
                newStr += str[i];
                ++charCount[s[i] - 'a'];
            }
        }
        for (int i{ 0 }; i < 26; ++i)
        {
            if (charCount[i] % 2 != 0)
                return 0;
            else
                charCount[i] = 0;
        }
        if (deletedString)
        {
            if (0 == newStr.size())
                return 1;
            else
            {
                str = newStr;
                newStr = "";
            }
        }
        else
            return 0;
    }
    return 0;
}

void main()
{
    solution("ppoooooopplaallllllaaaallalaall");
}