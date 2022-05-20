#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    int length = 1;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == ' ') // 문자열이 공백일때
        {
            length = 1;
            continue;
        }
        else if(length % 2 == 1) // 문자열이 짝수이자 , a~z 일때
        {
            if ('a' <= s[i] && s[i] <= 'z')
                s[i] -= 32;
        }
        else // 문자열이 홀수이고 A~Z 일때
        {
            if ('A' <= s[i] && s[i] <= 'Z')
                s[i] += 32;
        }
        ++length;
    }

    return s;
}

