#include <string>
#include <vector>
#include <math.h>
using namespace std;


void DFS(float x,int y,int n, int count, int& answer)
{
	if (x == y)
	{
		if (answer == -1)
			answer = count;
		else
			answer = count < answer ? count : answer;
		return;
	}
	else if ((fmod(x , (int)x) != 0) || (answer > 0 && count > answer) || x < y)
		return;
	

	DFS(x / 3,y, n, count + 1, answer);
	DFS(x / 2,y, n, count + 1, answer);
	DFS(x - n,y, n, count + 1, answer);
}

int solution(int x, int y, int n)
{
	int answer{ -1 };
	DFS(y , x , n, 0, answer);
	return answer;
}

void main()
{
	solution(10, 40, 5);
}