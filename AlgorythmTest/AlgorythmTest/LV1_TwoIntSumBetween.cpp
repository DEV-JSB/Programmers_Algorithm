#include <string>
#include <vector>

using namespace std;

long long Func(int small, int big)
{
    long long answer = 0;
    for (int i = small; i <= big; ++i)
        answer += i;
    return answer;
}

long long solution(int a, int b) {
    long long answer = 0;
    if (a < b)
    {
        return Func(a, b);
    }
    else
    {
        return Func(b, a);
    }
}