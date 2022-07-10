#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = n;
    bool borrow = false;
    for (int i = 0; i < lost.size(); ++i)
    {
        borrow = false;
        for (int j = 0; j < reserve.size(); ++j)
        {
            if (lost[i] == reserve[j] - 1 || lost[i] == reserve[j] + 1)
            {
                reserve[j] = -1;
                borrow = true;
                break;
            }
        }
        if (!borrow)
            --answer;
    }
    return answer;
}
void main()
{
    solution(5, vector<int>({ 1,2,3,4,5 }), vector<int>({ 0 }));
}