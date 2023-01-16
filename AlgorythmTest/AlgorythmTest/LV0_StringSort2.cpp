#include <string>
#include <vector>

using namespace std;

void SortString(string& _str)
{
    for (int i = 0; i < _str.length() - 1; ++i)
    {
        for (int j = i + 1; j < _str.length(); ++j)
        {
            if (_str[i] > _str[j])
            {
                char tmp = _str[i];
                _str[i] = _str[j];
                _str[j] = tmp;
            }
        }
    }
}

string solution(string my_string) {
    string answer = "";
    for (char a : my_string)
        answer += 'a' <= a ? a : a + 32;
    SortString(answer);
    return answer;
}
