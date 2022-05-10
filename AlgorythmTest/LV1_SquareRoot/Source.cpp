#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    // n이 양의 정수 x의 제곱이라면
    if (n % 2 == 0)
    {
        for (long long i = 2; i * i <= n; i += 2)
        {
            if (i * i == n)
            {
                answer = i + 1;
                return answer * answer;
            }
        }
        return -1;
    }
    else
    {
        for (long long i = 1; i * i <= n; i += 2)
        {
            if (i * i == n)
            {
                answer = i + 1;
                return answer * answer;
            }
        }
        return -1;
    }

}