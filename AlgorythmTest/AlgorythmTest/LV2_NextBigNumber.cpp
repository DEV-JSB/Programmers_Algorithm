#include <string>
#include <vector>
#include <math.h>

#include <iostream>
using namespace std;

void GetCombination(int bit, const int ZeroCount, const int OneCount, int one, int zero, string str, const int n, int* MinNum)
{
    str.push_back('0' + bit);
    if (bit)
        ++one;
    else
        ++zero;
    if (0 != str.size() && str[0] == '0')
        return;
    else if (((int)str.length() == ZeroCount + OneCount))
    {
        if (ZeroCount == zero && OneCount == one)
        {
            int num{ 1 };
            int tmp{ 0 };
            for (int i{ (int)str.length() - 1 }; 0 <= i; --i)
            {
                tmp += num * (str[i] - '0');
                num *= 2;
            }
            if (n < tmp && tmp < *MinNum)
                *MinNum = tmp;
            return;
        }
        else
            return;
    }

    GetCombination(1, ZeroCount, OneCount, one, zero, str, n, MinNum);
    GetCombination(0, ZeroCount, OneCount, one, zero, str, n, MinNum);

}

int solution(int n) {
    if (n == 1)
        return 2;
    int answer{ 1000000};
    int tmp{ n };
    string binaryStr{ "" };
    int ZeroCount{ 0 };
    int OneCount{ 0 };
    while (tmp)
    {
        tmp % 2 == 0 ? ++ZeroCount : ++OneCount;
        tmp /= 2;
    }
    if(0 == ZeroCount)
    {
        answer = n << 1;
        answer ^= (1 << OneCount - 1);
        ++answer;
    }
    else
    {
        int RealtimeZero{ 0 };
        int RealtimeOne{ 0 };
        GetCombination(1 , ZeroCount, OneCount, RealtimeOne, RealtimeZero, binaryStr, n, &answer);
    }
    
    return answer;
}

void main()
{
    solution(4);
}