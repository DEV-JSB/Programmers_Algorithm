#include <queue>
#include <iostream>

using namespace std;

void solution(int N, int K)
{
	queue<int> que;
	for (int i = 1; i <= N; ++i)
	{
		que.push(i);
	}

	while (que.size() > 1)
	{
		for (int i = 0; i < K; ++i)
		{
			que.push(que.front());
			que.pop();
		}
		que.pop();
	}
	
	cout << que.front();
}
