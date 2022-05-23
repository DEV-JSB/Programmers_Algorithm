#include <string>
#include <vector>
#include<iostream>
using namespace std;

string solution(int a, int b) {
    string answer;
    string Day[7] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
    int startDay[12] = { 5,1,2,5,0,3,5,1,4,6,2,4 };
    --a;
    for (int i = 2; i <= b; ++i)
    {
        if (6 < startDay[a] + 1)
        {
            startDay[a] = 0;
            continue;
        }
        startDay[a]++;
    }

    answer = Day[startDay[a]];
    return answer;
}
