
#include <iostream>

using namespace std;

bool solution(string s)
{
	int num = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		num += s[i] == '(' ? 1 : -1;
		if (num < 0)
			return false;
	}

	return num == 0;
}