#include <string>
#include <vector>

using namespace std;

bool MeasureCheck(const int a)
{
    int Count = 0;
    for (int i = 1; i < a; ++i)
    {
        if (0 == a % i)
            Count++;
    }
    if (Count % 2)
        return true;
    else
        return false;
    // 짝수 일 경우 true  반환
    // 홀수 일 경우 false 반환
}

int solution(int left, int right) {
    
    int answer = 0;
    for (int i = left; i <= right; ++i)
    {
        if (MeasureCheck(i))
            answer += i;
        else
            answer += -i;
    }
    return answer;
}