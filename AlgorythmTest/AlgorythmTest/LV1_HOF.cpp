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
    // k ��° ������ score ���� ���� ��� �ּڰ��� ���ؼ� �ִ´�.
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