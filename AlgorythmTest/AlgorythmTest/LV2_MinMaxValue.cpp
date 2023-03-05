#include <string>
#include <vector>

using namespace std;

struct Word
{
    int startIndex;
    int endIndex;
    int num;
};
int GetIntfromString(const string s, const int start, const int end)
{
    int tmp{};
    for (int i = start; i <= end; ++i)
    {
        if (s[i] == '-')
            continue;
        else
        {
            if (tmp != 0)
                tmp *= 10;
            tmp += s[i] - '0';
        }
    }
    return s[start] == '-' ? -tmp : tmp;
}
string solution(string s) {
    string answer = "";
    std::vector<Word> numInfo;
    Word tmp{};
    bool IsStartSetting{ false };
    for (int i{ 0 }; i < s.length(); ++i)
    {
        if (!IsStartSetting)
        {
            tmp.startIndex = i;
            IsStartSetting = true;
        }
        if (s[i] == ' '|| i + 1 == s.length())
        {
            s[i] == ' ' ? tmp.endIndex = i - 1 : tmp.endIndex = i;
            tmp.num = GetIntfromString(s, tmp.startIndex, tmp.endIndex);
            numInfo.push_back(tmp);
            IsStartSetting = false;
        }
    }
    int maxIndex{ 0 };
    int minIndex{ 0 };
    for (int i{ 1 }; i < numInfo.size(); ++i)
    {
        if (numInfo[i].num > numInfo[maxIndex].num)
            maxIndex = i;
        else if (numInfo[i].num < numInfo[minIndex].num)
            minIndex = i;
    }
    answer += s.substr(numInfo[minIndex].startIndex, numInfo[minIndex].endIndex - numInfo[minIndex].startIndex + 1);
    answer += ' ';
    answer += s.substr(numInfo[maxIndex].startIndex, numInfo[maxIndex].endIndex - numInfo[maxIndex].startIndex + 1);
    return answer;
}
