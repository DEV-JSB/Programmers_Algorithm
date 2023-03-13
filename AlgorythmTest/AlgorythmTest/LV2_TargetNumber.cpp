#include <string>
#include <vector>
using namespace std;

void DFS(bool isPlus,int& answer,vector<int>& numbers, int realtimeCount,const int target)
{
    if ((isPlus && numbers[realtimeCount] < 0) || (!isPlus && numbers[realtimeCount] > 0))
        numbers[realtimeCount] *= -1;

    if (realtimeCount == numbers.size() - 1)
    {
        
        int tmp{ 0 };
        for (int i : numbers)
            tmp += i;
        if(tmp == target)
            ++answer;
        return;
    }
    DFS(true, answer, numbers, realtimeCount + 1, target);
    DFS(false, answer, numbers, realtimeCount + 1, target);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    DFS(true, answer, numbers, 0, target);
    DFS(false, answer, numbers, 0, target);
    return answer;
}