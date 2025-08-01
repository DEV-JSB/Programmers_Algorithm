#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;
    answer.resize(prices.size(), 0);

    stack<int> indexStack;

    indexStack.push(0);
    for (int i = 1; i < prices.size() ; ++i)
    {
        while (!indexStack.empty())
        {
            if (i + 1 == prices.size())
            {
                answer[indexStack.top()] = i - indexStack.top();
                indexStack.pop();
            }
            else if (prices[indexStack.top()] <= prices[i])
            {
                indexStack.push(i);
                break;
            }
            else if (prices[indexStack.top()] > prices[i])
            {
                answer[indexStack.top()] = i - indexStack.top();
                indexStack.pop();
                if (indexStack.empty())
                {
                    indexStack.push(i);
                    break;
                }
            }
        }
    }

    return answer;
}

void main()
{
    solution({ 1,2,3,2,3 });
}