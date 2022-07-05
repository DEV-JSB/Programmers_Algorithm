#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<map>   
using namespace std;


bool cmp(const pair<int, double> a, const pair<int, double> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int* StageTryCount = new int[N];
    int* StageClearCount = new int[N];

    map<int, double> mapfailure;

    for (int i = 0; i < N; ++i)
    {
        StageTryCount[i] = 0;
        StageClearCount[i] = 0;
    }
    for (int i = 0; i < stages.size(); ++i)
    {
        // && �� ������ ��� �߸� �Ȥ� �ä��̿���!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        for (int j = 0; j < stages[i] && j < N; ++j)
        {
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
            mapfailure.insert({ i+1,0. });
            continue;
        }
        mapfailure.insert({ i+1,((double)StageTryCount[i] - (double)StageClearCount[i]) / (double)StageTryCount[i] });
    }
    vector<pair<int, double>> failurevec(mapfailure.begin(), mapfailure.end());
    sort(failurevec.begin(), failurevec.end(), cmp);

    for (int i = 0; i < N; ++i)
        answer.push_back(failurevec[i].first);

    delete[] StageTryCount;
    delete[] StageClearCount;
     
    return answer;
}

//     solution(5,std::vector<int>({ 3,3,3,3 }));


void main()
{
    solution(5,std::vector<int>({ 2,1,3,5,6,6,6 }));
}