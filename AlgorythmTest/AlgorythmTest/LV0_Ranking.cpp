#include <string>
#include <vector>

using namespace std;

int GetRank(vector<float>& _avg, float _myAvg)
{
    int Rank{ 1 };
    for (float f : _avg)
    {
        if (_myAvg < f)
            ++Rank;
    }
    return Rank;
}
vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;
    vector<float> avg;
    // 평균은 다 구했다
    for (vector<int> vec : score)
        avg.push_back(((float)(vec[0] + vec[1]) / 2.f));

    for (int i{ 0 }; i < (int)avg.size(); ++i)
        answer.push_back(GetRank(avg, avg[i]));

    return answer;
}