#include <string>
#include <vector>
#include<iostream>
using namespace std;


void GetTernary(int num,int* _sum,int* _answer)
{
    if (!num)
        return;
    GetTernary(num/3,_sum,_answer);
    *_answer += (num%3)*(*_sum);
    *_sum *= 3;
}

int solution(int n) {
    int answer = 0;
    int sum = 1;
    int num = n;

    GetTernary(n, &sum, &answer);
    return answer;
}


