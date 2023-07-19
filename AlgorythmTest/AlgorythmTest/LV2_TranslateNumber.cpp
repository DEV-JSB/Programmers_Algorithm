#include <string>
#include <vector>
using namespace std;

bool CheckingNumberIsCanMake(const int x, const int y, const int n)
{
	int num = y % 3;
	if (num % 2 == 0 || num % n == 0)
		return true;
	int num2 = y % 2;
	if (num2 % n == 0)
		return true;
	int num3 = y % n;
	if (!num3)
		return true;
	return false;
}

void DFS(int x, int y, int n, int count, int& answer)
{
	if (x == y)
	{
		if (answer == -1)
			answer = count;
		else
			answer = count < answer ? count : answer;
		return;
	}
	else if (x > y || (answer > 0 && count > answer)
		|| !CheckingNumberIsCanMake(x, y, n))
		return;
	DFS(x * 3, y, n, count + 1, answer);
	DFS(x * 2, y, n, count + 1, answer);
	DFS(x + n, y, n, count + 1, answer);
}

int solution(int x, int y, int n)
{
	// 연산이 제일 큰,, X3 을 먼저 확인해야 할 것 같다.
	int answer{ -1 };
	DFS(x, y, n, 0, answer);
	return answer;
}