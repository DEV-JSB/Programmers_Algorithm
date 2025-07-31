#include<iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
    stack<int> charIntStack;

    for (int i = 0; i < s.length(); ++i)
    {
        if (!charIntStack.empty() && charIntStack.top() == s[i])
        {
            charIntStack.pop();
        }
        else
        {
            charIntStack.push(s[i]);
        }
    }

    return charIntStack.empty() ? 1 : 0;
}