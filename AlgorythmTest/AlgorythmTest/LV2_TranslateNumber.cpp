#include <string>
#include <vector>
#include <queue>
using namespace std;


int solution(int x, int y, int n)
{
	if (x == y)
		return 0;
	queue<pair<int,int>> que;
	que.push({ x, 0 });
	//DFS(y, x, n, 0, answer);

	vector<int> answer(1000001, -1);

	while (!que.empty())
	{
		int num = que.front().first;
		int count = que.front().second;
		que.pop();

		if (num == y)
			return count;

		if (num + n <= y && -1 == answer[num + n])
		{
			que.push({ num + n ,count + 1 });
			answer[num + n] = count + 1;
		}
		if (num * 2 <= y && -1 == answer[num * 2])
		{
			que.push({ num * 2 , count + 1 });
			answer[num * 2] = count + 1;
		}
		if (num * 3 <= y && -1 == answer[num * 3])
		{
			que.push({ num * 3 , count + 1 });
			answer[num * 3] = count + 1;
		}
	}
	return -1;
}
