#include <string>
#include <vector>

using namespace std;

#define RESET_VALUE A = 0 ; B = 0; A_B = 0

void MinCheck(bool* _bIsMin, int& value)
{
    if (*_bIsMin)
        value *= -1;
    *_bIsMin = false;
}

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    int* Value{ nullptr };
    int A{};
    int B{};
    int A_B{};
    char cOpreator{ ' ' };
    bool isMin{ false };
    for (string str : quiz)
    {
        Value = &A;
        isMin = false;
        for (int i{ 0 }; i < (int)str.length(); ++i)
        {
            if (str[i] == '-')
                isMin = true;
            else if ('0' <= str[i] && '9' >= str[i])
            {
                if (*Value != 0)
                    *Value *= 10;
                *Value += str[i] - '0';
            }
            else if (' ' == str[i] 
                && (str[i+1] == '-' || str[i+1] == '+')
                && str[i+2] == ' ')
            {
                MinCheck(&isMin, *Value);
                cOpreator = str[i + 1];
                Value = &B;
                i += 2;
            }
            else if ('=' == str[i])
            {
                MinCheck(&isMin, *Value);
                Value = &A_B;
            }
        }
        MinCheck(&isMin, *Value);
        if (cOpreator == '-')
            B *= -1;
        A + B == A_B ? answer.push_back("O") : answer.push_back("X");
        RESET_VALUE;
    }
    return answer;
}