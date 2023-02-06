#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

unsigned long long Factorial(int excaption,int end)
{
    unsigned long long sum = excaption + 1;
    for (int i = sum + 1; i <= end; ++i)
    {
        sum *= i;
    }
    return sum;
}

unsigned long long Factorial2(int excaption, int end , unsigned long long denominator)
{
    bool Divide = false;
    unsigned long long sum = excaption + 1;
    for (int i = sum + 1; i <= end; ++i)
    {
        sum *= i;
        if (Divide == false && sum % denominator == 0)
        {
            sum /= denominator;
            Divide = true;
        }
    }
    return sum;
}

unsigned long long solution(int balls, int share) {
    if (balls == share)
        return 1;
    unsigned long long answer;
    if(balls - share > share)
        answer = Factorial2(balls - share , balls, Factorial(0, share));
    else
        answer = Factorial2(share, balls, Factorial(0, balls - share));
    return answer;
}
void main()
{
    solution(30, 2);
}