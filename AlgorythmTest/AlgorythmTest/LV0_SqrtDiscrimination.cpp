#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include<math.h>

int solution(int n) {
    double tmp = sqrt(n);
    double num = (int)tmp;
    tmp -= num;
    if (tmp != 0)
        return 2;
    else
        return 1;
}