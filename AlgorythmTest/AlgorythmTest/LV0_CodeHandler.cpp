#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string answer = "";
    int mode = 0;
    int idx = 0;
    for (char c : code)
    {
        if ('1' == c)
            mode = !mode;
        else if (0 == mode && idx % 2 == 0)
            answer += c;
        else if (1 == mode && idx % 2 == 1)
            answer += c;
        ++idx;
    }

    return answer == "" ? "EMPTY" : answer;
}

void main()
{
    solution("abc1abc1abc");
}