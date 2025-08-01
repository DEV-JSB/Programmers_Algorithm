#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) 
{
    vector<int> answer;
    
    stack<int> timeCounting;
    answer.resize(prices.size(), 0);
    for (int i = 0; i < prices.size(); ++i)
    {
        timeCounting.push(prices[i]);
        for (int j = 0; j < i; ++j)
        {
            if (timeCounting.top() >= prices[j])
            {
                ++answer[j];
            }
        }
    }

    return answer;
}

void main()
{
    solution({ 3,5,2,6,7,8,1,10,9 });
}