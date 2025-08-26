#include<unordered_map>
#include<iostream>	

using namespace std;


void mapping(vector<int>& hash, const vector<int>& arr, int target)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] > target)
		{
			continue;
		}
		hash[arr[i]] = 1;
	}
}

bool bookSolution(vector<int> arr, int target)
{
	vector<int> hash(target + 1, 0);
	mapping(hash, arr, target);

	for (int i = 0; i < arr.size(); ++i)
	{
		int num = target - arr[i];

		if (arr[i] == num)
		{
			continue;
		}
		if (num < 0)
		{
			continue;
		}
		if (hash[num])
		{
			return true;
		}

	}

}


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