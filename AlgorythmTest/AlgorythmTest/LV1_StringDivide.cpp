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

    firstWord = s[0];
    for (int i = 1 ; i < s.length();++i)
    {
        firstWord == s[i] ? ++correctCount : ++wrongCount;
        if (correctCount == wrongCount)
        {
            ++answer;
            correctCount = 1;
            wrongCount = 0;
            firstWord = s[i + 1];
            i = i + 1;
            // ³ª´³´Âµ¥ ¶§¸¶Ä§ µü ³ª´² ¶³¾îÁ³À»¶§ ¹ÝÈ¯ÇÑ´Ù
            if (i == s.length())
                return answer;
        }
    }
    return ++answer;
}
