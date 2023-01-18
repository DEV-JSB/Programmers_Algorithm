#include <string>
#include <vector>

using namespace std;

int GetMinScore(const vector<int>& _vec)
{
    int minNum = _vec[0];
    for (int i = 1; i < _vec.size(); ++i)
    {
        minNum = _vec[i] < minNum ? _vec[i] : minNum;
    }
    return minNum;
}

int CheckAndPush(vector<int>& _vec, int _iNewNum)
{

}

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> ranking;
    int i = 0;
    // k 번째 까지는 score 에서 들어온 대로 최솟값을 비교해서 넣는다.
    for (i = 0; i < k; ++i)
    {
        ranking.push_back(score[i]);
        answer.push_back(GetMinScore(ranking));
    }
    for (; i < score.size(); ++i)
    {
        
        ranking.push_back(score[i]);
        answer.push_back(GetMinScore(ranking));
    }

    return answer;
}