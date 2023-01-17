#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include<math.h>

int solution(int number, int limit, int power) {
    int answer = 1;
    
    int measureCount = 0;
    int j = 1;
    for (int i = 2; i <= number; ++i)
    {
        j = 1;
        measureCount = 0;
        for (j = 1; j * j < i; ++j)
            i % j == 0 ? ++measureCount : measureCount;
        if (j * j == i)
        {
            measureCount *= 2;
            ++measureCount;
        }
        else
            measureCount *= 2;
        answer += measureCount > limit ? power : measureCount;
    }
    return answer;
}
