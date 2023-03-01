#include <string>
#include <vector>

using namespace std;

bool IsInThree(int num)
{
    while (num)
    {
        if (num % 10 == 3)
            return true;
        num /= 10;
    }
    return false;
}

int solution(int n) {
    int answer{ 1 };
    for (int i{ 1 }; i <= n; ++i)
    {
        while(answer % 3 == 0 || IsInThree(answer))
            ++answer;
        ++answer;
    }
    return answer - 1;
}
