#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    int tmp = 0;
    for (char c : my_string)
    {
        if ('0' <= c && '9' >= c)
        {
            if (tmp != 0)
                tmp *= 10;
            tmp += c - '0';
        }
        else
        {
            answer += tmp;
            tmp = 0;
        }
    }
    if (tmp != 0)
        answer += tmp;
    return answer;
}