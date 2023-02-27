#include <string>
#include <vector>

using namespace std;

int GetNum(const string _str)
{
    int num{};
    for (int i{ (int)_str.length() - 1 },j{ 1 }; i >= 0; --i, j *= 2)
    {
        num += (_str[i] - '0') * j;
    }
    return num;
}

void MakeBinary(string& _str,int _num)
{
    if (_num < 2)
    {
        _str.push_back((_num % 2) + '0');
        return;
    }
    MakeBinary(_str,_num / 2);
    _str.push_back((_num % 2) + '0');
}

string solution(string bin1, string bin2) {
    string answer{};
    int answerNum = GetNum(bin1) + GetNum(bin2);
    MakeBinary(answer, answerNum);
    
    return answer;
}
