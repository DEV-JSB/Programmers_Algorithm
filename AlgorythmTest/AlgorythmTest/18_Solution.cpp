#include<unordered_map>
#include<iostream>	

using namespace std;


bool solution(vector<int> arr, int target)
{
	unordered_map<int, int> map;


	for (int i = 0; i < arr.size(); ++i)
	{
		map.insert({ arr[i], i });
	}
	for (int i = 0; i < arr.size(); ++i)
	{
		unordered_map<int, int>::iterator result = map.find(target - arr[i]);
		if (result != map.end() && result->second != i)
		{
			return true;
		}

	}
	return false;
}

void main()
{
	bool b = solution({ 2,3,5,9 }, 10);
}