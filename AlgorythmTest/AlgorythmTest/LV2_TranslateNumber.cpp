#include <string>
#include <vector>
#include <math.h>
using namespace std;


void DFS(float x, int y, int n, int count, int& answer)
{
	if ((x - (int)x) != 0 
		|| count >= answer
		|| x < y)
		return;
	else if (x == y)
	{
		answer = count;
		return;
	}
	DFS(x / 3, y, n, count + 1, answer);
	DFS(x / 2, y, n, count + 1, answer);
	DFS(x - n, y, n, count + 1, answer);
}

int solution(int x, int y, int n)
{
	int answer{ 1000001 };
	DFS(y, x, n, 0, answer);
	return answer == 1000001 ? -1 : answer;
}