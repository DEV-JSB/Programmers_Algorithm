#include<queue>
#include<iostream>	

using namespace std;

int main()
{
	queue<int> q;



	q.push(10);
	q.push(20);
	q.push(30);


	cout << "Front : " << q.front() << endl;

	while (!q.empty())
	{
		cout << q.front() << "를 큐에서 삭제했다" << endl;
		q.pop();
	}

	cout << "큐가 비어 있는강?" << (q.empty() ? "YES" : "NO") << endl;
}