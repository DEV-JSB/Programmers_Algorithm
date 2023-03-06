#include <string>
#include <vector>

using namespace std;
#define IS_SMALL_LETTER(c) ('a' <= c && 'z' >= c)
#define IS_NUM(c) ('0' <= c && '9'>=c)
string solution(string s) {
    bool isFrontChar{ true };
    for (int i{ 0 }; i < s.length(); ++i)
    {
        if (s[i] == ' ')
            isFrontChar = true;
        else if (isFrontChar && !IS_SMALL_LETTER(s[i]))
            isFrontChar = false;
        else if (isFrontChar && IS_NUM(s[i]))
            isFrontChar = false;
        else if (isFrontChar && IS_SMALL_LETTER(s[i]))
        {
            s[i] -= 32;
            isFrontChar = false;
        }
        else if (!isFrontChar && !IS_NUM(s[i]) && !IS_SMALL_LETTER(s[i]))
            s[i] += 32;
    }
    return s;
}