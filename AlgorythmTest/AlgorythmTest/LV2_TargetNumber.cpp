#include <string>
#include <vector>
using namespace std;

void DFS(int numberSum ,int& answer,vector<int>& numbers, int realtimeCount,const int target)
{
        if (realtimeCount == numbers.size())
        {
            if (numberSum == target)
                ++answer;
            return;
        }
    DFS(numberSum + numbers[realtimeCount], answer, numbers, realtimeCount + 1, target);
    DFS(numberSum - numbers[realtimeCount], answer, numbers, realtimeCount + 1, target);
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    DFS(0, answer, numbers, 0, target);

    return answer;
}
