#include <string>
#include <vector>
#include <stack>
using namespace std;
vector<int> solution(vector<int> numbers)
{
    vector<int> answer;
    vector<int> tmp;
    stack<int> bigNumber;
    answer.push_back(-1);
    bigNumber.push(numbers[numbers.size() - 1]);
    for (int i{ (int)numbers.size() - 2 }; i >= 0; --i)
    {
        while (!bigNumber.empty() && bigNumber.top() <= numbers[i])
            bigNumber.pop();
        if (bigNumber.empty())
            answer.push_back(-1);
        else
            answer.push_back(bigNumber.top());
        bigNumber.push(numbers[i]);
    }
    for (int i{ (int)answer.size() - 1 }; i >= 0; --i)
        tmp.push_back(answer[i]);
    return tmp;
}
