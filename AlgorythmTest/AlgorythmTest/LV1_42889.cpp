#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


struct StageFailureRate
{
    int stage;
    float failureRate;

    StageFailureRate(int stage, float failureRate)
        : stage(stage), failureRate(failureRate)
    {
    }
};
vector<int> solution(int N, vector<int> stages) 
{
    vector<int> answer;

    vector<StageFailureRate> stageFailureRates;

    
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
        stageFailureRates.push_back(StageFailureRate{ i,rate });
    }
    
    sort(stageFailureRates.begin(), stageFailureRates.end()
        , [](const StageFailureRate& a, const StageFailureRate& b)
        {
            return a.failureRate > b.failureRate;
        });

    for (StageFailureRate info : stageFailureRates)
    {
        answer.push_back(info.stage + 1);
    }

    return answer;
}


void main()
{
    solution(4, { 4,4,4,4,4 });
}