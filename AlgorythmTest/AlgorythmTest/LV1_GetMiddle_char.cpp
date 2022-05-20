#include <string>
#include <vector>

using namespace std;

string solution1(string s) {
    string answer = "";
    if (s.length() % 2 == 1)
        answer = s[s.length() / 2];
    else
    {
        answer += s[s.length() / 2 - 1];
        answer += s[s.length() / 2];
    }

    return answer;
}