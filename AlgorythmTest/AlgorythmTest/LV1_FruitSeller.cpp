#include <string>
#include <vector>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int scores[9]{};
    int inBoxCount = 0;

    // 사과를 m 개 담는다
    // socre 의 최소 가격에 따라서 상자의 가격이 정해진다.

    // 상자가 여러개라면 어떻게 해야할까?
    // 상자가 여러개면... 값이 싼거를 폭탄 처리를 해야하는데

    // 최댓값을 기준으로 상자에 차곡차곡 넣으면 될듯
    

    // 점수의 index 를 증가한다.
    for(int i = 0 ; i < score.size() ; ++i)
        ++scores[score[i] - 1];

    for (int i = 0; i < score.size() / m;)
    {
        for (int j = 9 - 1; -1 < j ;)
        {
            if (scores[j] != 0)
            {
                ++inBoxCount;
                scores[j]--;
            }
            if ((i + 1) * m == inBoxCount)
            {
                ++i;
                answer += m * (j + 1);
                break;
            }
            if(0 == scores[j])
                --j;
        }
    }

    return answer;
}

void main()
{
    solution(3, 4, { 1,2,3,1,2,3 });
}