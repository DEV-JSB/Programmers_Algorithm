#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;



//�� ����������
void PushAnswer(vector<int>& answer, vector<double>percent)
{
    int MaxIndex;
    while(answer.size()!=percent.size())
    {
        MaxIndex = 0;
        for (int j = 0; j < percent.size(); ++j)
        {
            if (percent[MaxIndex] < percent[j])
            {
                MaxIndex = j;
            }
        }
        percent[MaxIndex] = -1.f;
        answer.push_back(MaxIndex+1);
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
            // ���������� Ŭ���� �� Ƚ���� �����Ѵ�
            StageClearCount[j-1] +=1;
            // ���������� �õ��� Ƚ���� �����Ѵ�
            StageTryCount[j] += 1;
        }
    }
    for (int i = 0; i < N; ++i)
        failurePercent.push_back(((double)StageTryCount[i] - (double)StageClearCount[i]) / (double)StageTryCount[i]);
    PushAnswer(answer, failurePercent);

    delete[] StageClearCount; 
    delete[] StageTryCount;
    return answer;
}



void main()
{
    solution(5,std::vector<int>({ 2,1,2,6,2,4,3,3 }));
}