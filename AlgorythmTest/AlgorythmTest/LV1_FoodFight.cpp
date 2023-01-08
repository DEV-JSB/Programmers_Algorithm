#include <string>
#include <vector>

using namespace std;


struct foodInfo
{
    int idx;
    int count;
};

string solution(vector<int> food) {
    string answer = "";
    vector<foodInfo> counting;
    

    // 준비된 칼로리의 음식을 센다.
    // 준비된 음식을 넣을 횟수는 food /2 와 같다
    // 음식의 넘버링은 food[i] 의 i + 1 번째 index 이다.

    for (int i = 0; i < food.size(); ++i)
    {
        if (2 > food[i])
            continue;
        // 우선 카운트를 해서 넣는다.
        counting.push_back({ i,food[i] / 2 });
    }

    // 1 번째부터 음식을 넣는다
    for (int i = 0; i < counting.size(); ++i)
    {
        for(int j = 0 ; j < counting[i].count; ++j)
            answer += counting[i].idx + '0';
    }
    answer += '0';
    for (int i = counting.size() - 1; i >= 0; --i)
    {
        for (int j = 0; j < counting[i].count; ++j)
            answer += counting[i].idx + '0';
    }

    return answer;
}

void main()
{
    solution({1,3,4,6});
}