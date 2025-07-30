#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;



unordered_map<char, char> mapCharPair{ {'[',']'},{'(',')'},{'{','}'} };

bool IsValidPair(stack<char>& stack, char c)
{

    if (c == '}' || c == ']' || c == ')')
    {
        if (!stack.empty() && stack.top() == mapCharPair[c])
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
    return stack.empty();
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
            if (IsValidPair(charStack, s[j % (s.length())]))
            {
                ++checkCount;
            }
            else
            {
                break;
            }
        }
        if (checkCount == s.length())
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