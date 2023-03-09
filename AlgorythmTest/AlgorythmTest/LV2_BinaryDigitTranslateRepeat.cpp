#include <string>
#include <vector>

using namespace std;

#define ZEROCUT_COUNT 1
#define TRANSLATE_COUNT 0

void TranslateNumToBinaryString(const int i, string& str)
{
    if (i < 2)
    {
        str += '0' + i;
        return;
    }
    TranslateNumToBinaryString(i / 2, str);
    str += (i % 2) + '0';
}

vector<int> solution(string s) {
    vector<int> answer{ 0,0 };
    
    int OriginSize{ (int)s.length() };
    int ZeroCount{ 0 };
    while (true)
    {
        OriginSize = s.length();
        ZeroCount = 0;
        for (char c : s)
        {
            if ('0' == c)
                ++ZeroCount;
        }
        if (OriginSize - ZeroCount == 1)
        {
            ++answer[TRANSLATE_COUNT];
            answer[ZEROCUT_COUNT] += ZeroCount;
            break;
        }
        s = "";
        TranslateNumToBinaryString(OriginSize - ZeroCount, s);
        ++answer[TRANSLATE_COUNT];
        answer[ZEROCUT_COUNT] += ZeroCount;
    }
    return answer;
}