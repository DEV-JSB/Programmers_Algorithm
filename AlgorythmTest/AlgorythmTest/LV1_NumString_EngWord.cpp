#include <string>
#include <vector>
#include<iostream>
using namespace std;

long long solution(string s) {
    long long answer = 0;
    string NumArr[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
    for (int i = 0; i < s.length(); ++i)
    {
        if ('0' <= s[i] && s[i] <= '9')
            answer += s[i] - '0';
        else
        {
            for (int j = 0; j < 10; ++j)
            {
                if (s[i] == NumArr[j][0] && s[i + 1] == NumArr[j][1])
                {
                    answer += j;
                    i += NumArr[j].length() - 1;
                    break;
                }
            }
        }
        if (i + 1 == s.length())
        {
            break;
        }
        answer *= 10;
    }
    return answer;
}