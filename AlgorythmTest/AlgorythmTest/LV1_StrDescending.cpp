#include <string>
#include <vector>

using namespace std;

string Descending(string _str)
{
    string str = _str;
    int tmp;
    for (int i = 0; i < str.size() - 1; ++i)
    {
        for (int j = i + 1; j < str.size(); ++j)
        {
            if (str[i] < str[j])
            {
                tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
        }
    }
    return str;
}


string solution(string s) {
    string answer = "";
    answer = Descending(s);
    return answer;
}

