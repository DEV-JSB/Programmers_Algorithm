#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


bool IsDecimal(const int num)
{
    for (int i = 2; i * i <= num; ++i)
    {
        if (0 == num % i)
            return false;
    }
    return true;
}


int solution(int a, int b) {

    // 두 분모 , 분자가 정수인 경우
    int smallNum = a < b ? a : b;
    // 더이상 나눌 수 없는 상태 , 기약분수로 만드는 과정이다.
    for (int i = 2; i <= smallNum; ++i)
    {
        while (a % i == 0 && b % i == 0)
        {
            a /= i;
            b /= i;
        }
    }
    // b == 1 인 경우 정수이므로 1 을 반환
    if (b == 1)
        return 1;
    for (int i = 2; i <= b; ++i)
    {
        if (b % i == 0 && IsDecimal(i))
        {
            if ((i != 5) && (i != 2))
                return 2;
        }
    }
    return 1;
}
