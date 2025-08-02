#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;
    answer.resize(prices.size(), 0);

    stack<int> indexStack;

    for (int i = 0; i < prices.size() ; ++i)
    {
        while (!indexStack.empty() && prices[indexStack.top()] > prices[i])
        {
            answer[indexStack.top()] = i - indexStack.top();
            indexStack.pop();
        }
        indexStack.push(i);
    }

    int top = indexStack.top();

    while (!indexStack.empty())
    {
        answer[indexStack.top()] = top - indexStack.top();
        indexStack.pop();
    }

    return answer;
}

void main()
{
    solution({ 1,4,5,1,2,3,5,1,5 });
}