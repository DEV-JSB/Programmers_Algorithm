#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    queue<int> que;
    for (int i = 0; i < progresses.size(); ++i)
    {
        int remainWork = 100 - progresses[i];
        int workDay = remainWork % speeds[i] == 0 ? remainWork / speeds[i]
            : remainWork / speeds[i] + 1;
        que.push(workDay);
    }


    while (!que.empty())
    {
        int popCount = 0;
        int day = que.front();
        while (!que.empty() && que.front() <= day)
        {
            ++popCount;
            que.pop();
        }
        answer.push_back(popCount);
    }

    return answer;
}

void main()
{
    solution({95,90,99,99,80,99}, {1,1,1,1,1,1});
}