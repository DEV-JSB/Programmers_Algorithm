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
    // ¦�� �� ��� true  ��ȯ
    // Ȧ�� �� ��� false ��ȯ
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