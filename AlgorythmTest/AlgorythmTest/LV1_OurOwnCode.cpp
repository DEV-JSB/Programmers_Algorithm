#include <string>
#include <vector>

using namespace std;


//int GetJumpCount(const bool* _arrSkipWords, int _count, const char _word)
//{
//    int Counting = _count;
//    char word = _word;
//    for (int i = 1; i <= Counting; ++i,++word)
//    {
//        if (word + 1 > 'z')
//        {
//            if (_arrSkipWords[word - 'z'] == true)
//                ++Counting;
//        }
//        else if (_arrSkipWords[(word + 1) - 'a'] == true)
//            ++Counting;
//    }
//    return Counting;
//}

string solution(string s, string skip, int index) {
    string answer = "";
    int SkipCount = index;
    bool skipWord[26]{ false };

    for (char word : skip)
    {
        skipWord[word - 'a'] = true;
    }

    // s 의 길이 만큼 반복한다.
    for (int i = 0; i < s.length(); ++i)
    {
        SkipCount = index;
        char word = s[i];
        for (int i = 1; i <= SkipCount; ++i)
        {
            ++word;
            word = word > 'z' ? word = '`' + (word - 'z') : word;
            if (skipWord[word - 'a'] == true)
                ++SkipCount;
        }

        answer += word > 'z' ? word = '`' + (word - 'z') : word;

    }
    return answer;
}

void main()
{
    solution("ybcde", "az", 1);
}