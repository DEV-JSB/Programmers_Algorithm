#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    if (1 == s.length())
        return 0;
    int answer = 0;
    char firstWord;
    int correctCount = 1;
    int wrongCount = 0;
    int strLength = s.length();

    firstWord = s[0];
    for (int i = 1 ; 1 < s.length();)
    {
        firstWord == s[i] ? ++correctCount : ++wrongCount;
        if (correctCount == wrongCount)
        {
            ++answer;
            s = s.substr(correctCount + wrongCount, s.length());
            correctCount = 0;
            wrongCount = 0;
            strLength = s.length();
            i = 0;
        }
        else if (strLength == i + 1)
        {
            if (s[0] == firstWord && (correctCount == s.length() || wrongCount == s.length()))
                return ++answer;
            else
            {
                correctCount = 1;
                wrongCount = 0;
                i = 1;
                firstWord = s[0];
                strLength = s.length();
            }
        }
        else
            ++i;
    }
    return 0 < s.length() ? ++answer : answer;
}

void main()
{
    solution("zcbbbbbbbbbbbbb");
}