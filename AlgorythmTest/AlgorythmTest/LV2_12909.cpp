
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
	stack<char> test;

	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == '(')
		{
			test.push(s[i]);
		}
		else
		{
			if (test.empty())
			{
				return false;
			}
			test.pop();
		}
	}

	return test.empty();
}

void main() {
	solution("(())");
}