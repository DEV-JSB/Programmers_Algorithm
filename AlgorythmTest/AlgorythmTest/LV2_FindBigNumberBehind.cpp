//#include <string>
#include <vector>
#include <stack>
using namespace std;
vector<int> solution(vector<int> numbers)
{
    vector<int> answer;
    stack<int> willBeAnswer;
    stack<int> bigStack;

    willBeAnswer.push(-1);
    bigStack.push(numbers[numbers.size() - 1]);

    for (int i{ (int)numbers.size() - 2 }; 0 <= i; --i)
    {
        while (!bigStack.empty() && bigStack.top() <= numbers[i])
            bigStack.pop();
        if (bigStack.empty())
        {
            bigStack.push(numbers[i]);
            willBeAnswer.push(-1);
        }
        else
        {
            willBeAnswer.push(bigStack.top());
            bigStack.push(numbers[i]);
        }
    }


    while (!willBeAnswer.empty())
    {
        answer.push_back(willBeAnswer.top());
        willBeAnswer.pop();
    }
    return answer;
}