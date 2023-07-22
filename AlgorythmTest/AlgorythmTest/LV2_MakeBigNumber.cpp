#include <string>
#include <vector>

using namespace std;


bool ThisIndexIsBigNumber(int index, vector<int>& info)
{
	for (int i = index + 1; i < info.size() ; ++i)
	{
		if (0 != info[i])
		{
			return false;
		}
	}
	--info[index];
	return true;
}

string solution(string number, int k) 
{
	vector<int>numInfo(10, 0);
	string answer = "";
	for (char c: number)
		++numInfo[c - '0'];
	for (int i = 0; answer.length() < number.length() - k; ++i)
	{
		if (ThisIndexIsBigNumber(number[i] - '0', numInfo))
			answer += number[i];
	}
	return answer;
}

void main()
{
	printf("%s",solution("1231234", 2));
}