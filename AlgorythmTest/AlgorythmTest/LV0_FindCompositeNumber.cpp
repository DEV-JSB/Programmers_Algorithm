#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int divideCount = 0;
    for (int i = 4; i <= n; ++i)
    {
        divideCount = 2;
        for (int j = 2; j * j <= i; ++j)
        {
            if (i % j == 0)
                ++divideCount;
            if (divideCount > 2)
            {
                ++answer;
                break;
            }
        }
    }
    return answer;
}