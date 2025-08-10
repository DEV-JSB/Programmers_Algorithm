#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(string s)
{
    
    int answer = 0;
    stack<int> numStack;
    int num = 0;
    int cutStartIndex = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'Z')
        {
            numStack.pop();
        }
        else if (s[i] == ' ')
        {
            if (s[cutStartIndex] != 'Z')
            {
                num = stoi(s.substr(cutStartIndex, i - cutStartIndex));
                numStack.push(num);
            }
            cutStartIndex = i + 1;
        }
        else if (i + 1 == s.size())
        {
            if (s[cutStartIndex] != 'Z')
            {
                num = stoi(s.substr(cutStartIndex));
                numStack.push(num);
            }
        }
    }

    while (!numStack.empty())
    {
        answer += numStack.top();
        numStack.pop();
    }

    return answer;
}


void main()
{
    solution("1 2 Z 5");
}