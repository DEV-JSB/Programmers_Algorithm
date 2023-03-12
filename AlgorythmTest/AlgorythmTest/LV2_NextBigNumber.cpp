#include <string>
#include <vector>
#include <math.h>

#include <iostream>
using namespace std;


int solution(int n) {
    int answer{ 0};
    int tmp{ n };
    int tmp1{ 0 };
    int OneCount{ 0 };
    int OtherOneCount{ 0 };
    while (tmp)
    {
        if (tmp % 2)
            ++OneCount;
        tmp /= 2;
    }
    tmp = n;
    while (true)
    {
        OtherOneCount = 0;
        ++tmp;
        tmp1 = tmp;
        while (tmp1)
        {
            if (tmp1 % 2)
                ++OtherOneCount;
            tmp1 /= 2;
        }
        if (OneCount == OtherOneCount)
        {
            answer = tmp;
            break;
        }
    }
    return answer;
}
