#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
    stack<char> strStack;
    for (size_t i{ 0 }; i < s.length(); ++i)
    {
        if (strStack.empty())
            strStack.push(s[i]);
        else if (strStack.top() == s[i])
            strStack.pop();
        else
            strStack.push(s[i]);
    }
    if (strStack.size() == 0)
        return 1;
    else
        return 0;

}