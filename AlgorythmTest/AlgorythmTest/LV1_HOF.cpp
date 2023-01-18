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


// 제일 작은 랭킹의 숫자를 빼기 위한 함수
// 제일 작은 수를 찾아서 큰지 비교한 후 교체를 한다.
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
    // k 번째 까지는 score 에서 들어온 대로 최솟값을 비교해서 넣는다.
    for (i = 0; i < k && i < score.size(); ++i)
    {
        ranking.push_back(score[i]);
        answer.push_back(GetMinScore(ranking));
    }
    for (; i < score.size(); ++i)
        answer.push_back(CheckAndPush(ranking,score[i]));

    return answer;
}