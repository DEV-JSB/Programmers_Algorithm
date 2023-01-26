#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    int Mode = 0;
    int numberCount[1001]{ 0 };
    for (int num : array)
        ++numberCount[num];
    // 최빈값을 파악한다
    for (int i = 0; i < 1001; ++i)
    {
        if (Mode < numberCount[i])
        {
            answer = i;
            Mode = numberCount[i];
        }
    }
    // 같은 최빈값을 가진 친구가 있는지 확인한다
    for (int i = 0; i < 1001; ++i)
    {
        if (Mode == numberCount[i] && answer != i)
            return -1;
    }
    return answer;
}

void main()
{
    solution({ 1000 });
}