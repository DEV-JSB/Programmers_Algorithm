#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    int multiNum = 1;
    int bigNum;
    // 제일 큰 값을 찾는다
    std::sort(arr.begin(), arr.end());
    bigNum = arr[arr.size() - 1] * multiNum;

    while (multiNum)
    {
        answer = bigNum * multiNum;
        for (int i = 0; i < arr.size(); ++i)
        {
            if (i == arr.size() - 1)
                return answer;
            else
            {
                if (answer % arr[i] != 0)
                {
                    ++multiNum;
                    break;
                }
            }
        }
    }
}

void main()
{
    solution(std::vector<int>({ 2,6,8,14 }));
}