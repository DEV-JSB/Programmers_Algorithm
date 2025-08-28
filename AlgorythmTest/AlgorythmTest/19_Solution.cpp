#include<unordered_map>
#include<iostream>	
#include<math.h>

using namespace std;

int Hashing(string& str)
{
	int mersenneNumber = 31;
	int m = 1000000007;
	int key = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		int num = (str[i] - 'a') * pow(mersenneNumber, i);
		num %= m;
		key += num;
	}
	return key % m;
}


long long polynomial_hash(const string& str)
{
	const int p = 31;
	const long long m = 1000000007;
	long long hash_value = 0;

	for (char c : str)
	{
		hash_value = (hash_value * p + c) % m;
	}
	return hash_value;
}

long long hash(const string& str)
{
	long long hashValue = 0;
	long long base = 31;
	long long mod = 1000000007;
	long long power = 1;

	for (char c : str)
	{
		hashValue = (hashValue + ((c - 'a' + 1) * power) % mod) % mod;
		power = (power * base) % mod;
	}

	return hashValue % mod;
}


vector<bool> solution(vector<string> string_list, vector<string> query_list)
{
	vector<int> hashTable;
	vector<bool> answer;
	hashTable.resize(1000000007, 0);

	for (string str : string_list)
	{
		int index = Hashing(str);
		hashTable[index] = 1;
	}

	for (string str : query_list)
	{
		int index = Hashing(str);
		if (hashTable[index] == 1)
		{
			answer.push_back(true);
		}
		else
		{
			answer.push_back(false);
		}
	}
	return answer;
}


int main()
{
	solution({ "apple","banana","cherry" }, { "banana","kiwi","melon","apple" });
}