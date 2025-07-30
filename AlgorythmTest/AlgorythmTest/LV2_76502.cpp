#include <string>
#include <vector>
#include <stack>

using namespace std;

char GetPair(char c)
{
    switch (c)
    {
    case '}':
        return '{';
    case ']':
        return '[';
    case ')':
        return '(';
    }
}

bool CheckValidPair(stack<char>& stack, char c)
{

    if (c == '}' || c == ']' || c == ')')
    {
        if (!stack.empty() && stack.top() == GetPair(c))
        {
            stack.pop();
        }
        else
        {
            return false;
        }
    }
    else
    {
        stack.push(c);
    }
    return true;
}

int solution(string s)
{
    int answer = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        int checkCount = 0;
        stack<char> charStack;
        for (int j = i; j < i + s.length(); ++j)
        {
            if (CheckValidPair(charStack, s[j % (s.length())]))
            {
                ++checkCount;
            }
            else
            {
                break;
            }
        }
        if (charStack.empty() && checkCount == s.length())
        {
            ++answer;
        }

    }

    return answer;
}

void main()
{
    solution("[](){}");
}