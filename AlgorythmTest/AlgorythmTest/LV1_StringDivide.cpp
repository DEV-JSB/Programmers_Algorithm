#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    if (1 == s.length())
        return 0;
    int answer = 0;
    string tmp = s;
    char firstWord;
    int correctCount;
    int wrongCount;

    for (int i = 0; 1 < tmp.length(); ++i)
    {
        firstWord = tmp[0];
        correctCount = 0;
        wrongCount = 0;
        for (int j = 0; j < tmp.length(); ++j)
        {
            firstWord == tmp[j] ? ++correctCount : ++wrongCount;
            if (correctCount != 0 && correctCount == wrongCount)
            {
                ++answer;
                tmp = tmp.substr(correctCount + wrongCount, tmp.length());
                correctCount = 0;
                wrongCount = 0;
                j = -1;
                continue;
            }
        }
    }
    
    return 0 < tmp.length() ? ++answer : answer;
}

void main()
{
    solution("aaabbaccccabba");
}