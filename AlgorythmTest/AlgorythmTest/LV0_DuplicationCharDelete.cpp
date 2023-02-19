#include <string>
#include <vector>

using namespace std;

#define BLINK 52

string solution(string my_string) {
    string answer = "";
    bool isAppeared[53]{ false };

    for (char c : my_string)
    {
        if ('A' <= c && c <= 'Z')
        {
            if (isAppeared[c - 'A'] == false)
            {
                isAppeared[c - 'A'] = true;
                answer += c;
            }
        }
        else if('a' <= c && c <= 'z' )
        {
            if (isAppeared[26 + (c - 'a')] == false)
            {
                isAppeared[26 + (c - 'a')] = true;
                answer += c;
            }
        }
        else if (' ' == c)
        {
            if (isAppeared[BLINK] == false)
            {
                isAppeared[BLINK] = true;
                answer += c;
            }
        }
    }

    return answer;
}