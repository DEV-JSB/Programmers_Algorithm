#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;



vector<int> solution(int N, vector<int> stages) 
{
    vector<int> answer;

    vector<pair<int,float>> stageFailureRates;

    
    for (int i = 0; i < N; ++i)
    {
        int clearCount = 0;
        int tryCount = 0;
        for (int stage : stages)
        {
            if (i <= stage - 1)
            {
                ++tryCount;
                if (i < stage - 1)
                {
                    ++clearCount;
                }
            }
        }
        float rate = 0;
        if (tryCount != 0)
        {
            rate = (float)(tryCount - clearCount) / (float)tryCount;
        }
        stageFailureRates.push_back(make_pair(i, rate));
    }
    
    sort(stageFailureRates.begin(), stageFailureRates.end()
        , [](const pair<int,float>& a, const pair<int, float>& b)
        {
            if (a.second == b.second)
            {
                return a.first < b.first;
            }
            return a.second > b.second;
        });

    for (pair<int, float> info : stageFailureRates)
    {
        answer.push_back(info.first + 1);
    }

    return answer;
}


void main()
{
    solution(4, { 4,4,4,4,4 });
}