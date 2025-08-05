#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    stack<int> tmp;

    for (int num : arr)
    {
        if (!tmp.empty() && tmp.top() == num)
        {
            continue;
        }
        tmp.push(num);
        answer.push_back(num);
    }

    return answer;
}