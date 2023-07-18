#include <string>
#include <vector>
#include <algorithm>
using namespace std;


void DFS(int x, int y, int n , int count,int& answer)
{
	if (x == y)
	{
		if (answer == -1)
			answer = count;
		else
			answer = count < answer ? count : answer;
		return;
	}
	else if (x > y)
		return;
	DFS(x * 3, y, n , count + 1, answer);
	DFS(x * 2, y, n, count + 1, answer);
	DFS(x + n, y, n , count + 1, answer);
}

int solution(int x, int y, int n) 
{
	// 연산이 제일 큰,, X3 을 먼저 확인해야 할 것 같다.
	int answer{-1};
	DFS(x, y, n, 0, answer);
	return answer;
}