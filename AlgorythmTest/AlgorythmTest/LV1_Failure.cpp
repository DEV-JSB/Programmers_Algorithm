#include<iostream>
#include <string>
#include <vector>

using namespace std;



//걍 삽입정렬해
void PushAnswer(vector<int>& answer, vector<double>percent)
{
    int MaxIndex;
    while(answer.size()!=percent.size())
    {
        MaxIndex = 0;
        for (int j = 0; j < percent.size(); ++j)
        {
            if (percent[MaxIndex] < percent[j])
                MaxIndex = j;
        }
        percent[MaxIndex] = -1.f;
        answer.push_back(MaxIndex + 1);
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<double> failurePercent;
    int* StageTryCount = new int[N];
    int* StageClearCount = new int[N];

    for (int i = 0; i < N; ++i)
    {
        StageTryCount[i] = 0;
        StageClearCount[i] = 0;
    }
    for (int i = 0; i < stages.size(); ++i)
    {
        for (int j = 0; j < stages[i]; ++j)
        {
            // 6인데 , 사실상 5의 인덱스는 접근하면 안됨
            if (j == N)
            {
                StageClearCount[j-1] += 1;
                StageTryCount[j - 1] += 1;
                break;
            }
            // 스테이지를 시도한 횟수를 저장한다
            StageTryCount[j] += 1;
            // 스테이지를 클리어 한 횟수를 저장한다
            // 밑의 로직은 맞지 않은 것 같다.
            if (j == stages[i] - 1)
                continue;
            StageClearCount[j] += 1;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        if (StageTryCount[i] == 0)
        {
            failurePercent.push_back(0);
            continue;
        }
        failurePercent.push_back(((double)StageTryCount[i] - (double)StageClearCount[i]) / (double)StageTryCount[i]);
    }
    PushAnswer(answer, failurePercent);

    delete[] StageTryCount;
    delete[] StageClearCount;

    return answer;
}

//     solution(5,std::vector<int>({ 3,3,3,3 }));


void main()
{
    solution(10,std::vector<int>({ 5,4,3,2 }));
}