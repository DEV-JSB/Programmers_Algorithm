#include<iostream>
#include <vector>	
#include <algorithm>
using namespace std;

int main()
{
	vector<int> tmp{ 1,1,1,100,100,100,5,5,5 };

	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	for (auto iterator = tmp.rbegin(); iterator != tmp.rend(); ++iterator)
	{
		cout << *iterator << ", ";
	}
	return 0;
}