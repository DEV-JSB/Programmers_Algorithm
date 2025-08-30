#include<unordered_map>
#include<iostream>
#include<vector>

using namespace std;


int siz = 100000000;

long long Hash(const string& str)
{
    long long mercenne = 31;
    long long key = 0;
    for(char c : str)
    {
        key = (key * mercenne + c) % siz;
    }
    return key;
}


string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";

    unordered_map<long long, int> hashTable;

    for (string str : completion)
    {
        long long key = Hash(str);
        auto iter = hashTable.find(key);
        if (iter != hashTable.end())
        {
            iter->second++;
        }
        else
        {
            hashTable.insert(make_pair(key, 1));
        }
    }

    for (string str : participant)
    {
        long long key = Hash(str);
        auto iter = hashTable.find(key);
        if (iter == hashTable.end() || iter->second <= 0)
        {
            return str;
        }
        else
        {
            iter->second--;
        }
    }

    return answer;
}
