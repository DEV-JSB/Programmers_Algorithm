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


// ���� ���� ��ŷ�� ���ڸ� ���� ���� �Լ�
// ���� ���� ���� ã�Ƽ� ū�� ���� �� ��ü�� �Ѵ�.
int CheckAndPush(vector<int>& _vec, int _iNewNum)
{
    int minIdex = 0;
    int swapTmp = 0;
    for (int i = 1; i < _vec.size(); ++i)
        minIdex = _vec[i] < _vec[minIdex] ? i : minIdex;
    
    if (_vec[minIdex] < _iNewNum)
    {
        _vec[minIdex] = _iNewNum;
        return GetMinScore(_vec);
    }
    else
        return _vec[minIdex];
}

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> ranking;
    int i = 0;
    // k ��° ������ score ���� ���� ��� �ּڰ��� ���ؼ� �ִ´�.
    for (i = 0; i < k && i < score.size(); ++i)
    {
        ranking.push_back(score[i]);
        answer.push_back(GetMinScore(ranking));
    }
    for (; i < score.size(); ++i)
        answer.push_back(CheckAndPush(ranking,score[i]));

    return answer;
}