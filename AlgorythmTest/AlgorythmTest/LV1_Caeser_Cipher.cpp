#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = s;
    for (int i = 0; i < s.size(); ++i)
    {
        if (('a' <= s[i] && s[i] <= 'z'))
        {
            if ('z' < s[i] + n)
                answer[i] = 96 + (n - ('z' - s[i]));
            else
                answer[i] = s[i] + n;
        }
        else if(('A' <= s[i] && s[i] <= 'Z'))
        {
            if ('Z' < s[i] + n)
                answer[i] = 64 + (n - ('Z' - s[i]));
            else
                answer[i] = s[i] + n;
        }
    }
    return answer;
}
