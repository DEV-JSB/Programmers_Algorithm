#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = n;
    for (int i = 0; i < lost.size(); ++i)
    {
        for (int j = 0; j < reserve.size(); ++j)
        {
            if (lost[i] == reserve[j] - 1 || lost[i] == reserve[j] + 1)
                reserve[j] = -1;
            else if (lost[i] != reserve[j] - 1 || lost[i] != reserve[j] + 1)
                --answer;
        }
    }
    return answer;
}