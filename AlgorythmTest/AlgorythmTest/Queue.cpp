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
		cout << q.front() << "�� ť���� �����ߴ�" << endl;
		q.pop();
	}

	cout << "ť�� ��� �ִ°�?" << (q.empty() ? "YES" : "NO") << endl;
}