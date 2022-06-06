#include <string>
#include<vector>

#define DOUBLE 1
#define TRIPLE 2

using namespace std;

int Getsqrt(int& num, int count)
{
    int n = num;
    for (int i = 0; i < count; ++i)
    {
        num *= n;
    }
    return num;
}

int solution(string dartResult) {
    int answer = 0;
    vector<int> tmp;
    for (int i = 0; i < dartResult.size(); ++i)
    {
        // 1 ~ 9 까지의 사이 숫자일 때 
        if ('0' <= dartResult[i] && dartResult[i] <= '9')
        {
            if (0 != i)
                tmp.push_back(answer);
            answer = 0;
            // 10일때 점수 10점
            if ('0' == dartResult[i + 1])
            {
                answer = 10;
                ++i;
            }
            else
                answer = dartResult[i] - '0';
        } 
        // D , T 일경우 제곱
        else if ('S' == dartResult[i] || 'D' == dartResult[i] || 'T' == dartResult[i])
        {
            switch (dartResult[i])
            {
            case 'D':
                Getsqrt(answer, DOUBLE);
                break;
            case 'T':
                Getsqrt(answer, TRIPLE);
                break;
            }
        }
        else if ('*' == dartResult[i])
        {
            if(!tmp.size() == 0)
                tmp[tmp.size() - 1] *= 2;
            answer *= 2;
        }
        else if ('#' == dartResult[i])
        {
            answer *= -1;
        }
    }
    tmp.push_back(answer);
    answer = 0;
    for (int i = 0; i < tmp.size(); ++i)
    {
        answer += tmp[i];
    }

    return answer;
}
