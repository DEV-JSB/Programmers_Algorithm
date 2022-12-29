#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b, int n) {

    int answer = 0;
    int getColaCount = 0;
    while (n >= a)
    {
        getColaCount = (n / a) * b;
        n = getColaCount + n % a;
        answer += getColaCount;
    }
    return answer;
}

void main()
{
    solution(2, 1, 20);
}