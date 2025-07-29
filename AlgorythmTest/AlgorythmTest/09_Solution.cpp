//10������ 2������ ��ȣ���ϱ�

#include <iostream>	
#include <stack>	


using namespace std;


string solution(int decimal)
{
	if (decimal == 0)
	{
		return "0";
	}
	string answer;

	stack<char> charStack;

	while (decimal > 0)
	{
		charStack.push((decimal % 2) + '0');
		decimal /= 2;
	}

	while (!charStack.empty())
	{
		char c = charStack.top();
		charStack.pop();
		answer += c;
	}
	return answer;
}
