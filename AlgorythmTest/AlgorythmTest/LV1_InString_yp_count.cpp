#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int Pcount = 0;
    int Ycount = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == 'p' || s[i] == 'P')
            ++Pcount;
        else if (s[i] == 'y' || s[i] == 'Y')
            ++Ycount;
    }
    if(Pcount != Ycount)
        answer = false;
    return answer;
}