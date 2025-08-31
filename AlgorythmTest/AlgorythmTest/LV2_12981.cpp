#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


long long hashTableCount = 10000000000000000;

long long Hash(const string& str)
{
    long long value = 0;
    long long mersenne = 31;
    char word = 0;
    for (const char c : str)
    {
        value = ((value * mersenne) + c) % hashTableCount;
        word = c;
    }
    return value;
}

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer;
    answer.resize(2, 0);
    unordered_map<long long, int> hash;

    int count = 0;
    char lastWord = words[0].front();
    for (int i = 0; i < words.size(); ++i)
    {
        if (i % n == 0)
        {
            ++count;
        }
        long long key = Hash(words[i]);

        if (lastWord != words[i].front()
            || hash.find(key) != hash.end())
        {
            answer[0] = (i % n) + 1;
            answer[1] = count;
            return answer;
        }
        lastWord = words[i].back();
        hash.insert(make_pair(key, 1));
    }
    return answer;
}

void main()
{
    solution(3, { "tank", "tank", "know", "wheel", "land", "dream", "mother", "robot", "tank" });
}