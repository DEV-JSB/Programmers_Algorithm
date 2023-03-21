#include <iostream>
#include<string>
using namespace std;


// baabaa

int solution(string s)
{
    char prevChar{ ' ' };
    string str{ s };
    string newStr{ "" };
    bool deletedString{ false };
    while (true)
    {
        for (size_t i{ 0 }; i < str.length(); ++i)
        {
            if (str[i] == str[i + 1])
            {
                ++i;
                deletedString = true;
                continue;
            }
            else
                newStr += str[i];
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