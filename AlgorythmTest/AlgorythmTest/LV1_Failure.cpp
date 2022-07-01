#include<iostream>
#include <string>
#include <vector>

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
            // 6�ε� , ��ǻ� 5�� �ε����� �����ϸ� �ȵ�
            if (j == N)
            {
                StageClearCount[j-1] += 1;
                StageTryCount[j - 1] += 1;
                break;
            }
            // ���������� �õ��� Ƚ���� �����Ѵ�
            StageTryCount[j] += 1;
            // ���������� Ŭ���� �� Ƚ���� �����Ѵ�
            // ���� ������ ���� ���� �� ����.
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