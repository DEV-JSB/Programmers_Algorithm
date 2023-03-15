#include <string>
#include <vector>
#include <map>

using namespace std;

void Sort(vector<int>& count)
{
    int bigNumIndex{ 0 };
    for (size_t i{ 0 }; i < count.size(); ++i)
    {
        bigNumIndex = i;
        for (size_t j{ i + 1 }; j < count.size(); ++j)
        {
            if (count[bigNumIndex] < count[j])
                bigNumIndex = j;
        }
        int tmp = count[bigNumIndex];
        count[bigNumIndex] = count[i];
        count[i] = tmp;
    }
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> tangerineCount;
    vector<int>tangerineCountVec;
    for (int i : tangerine)
    {
        if (tangerineCount.find(i - 1) == tangerineCount.end())
            tangerineCount.insert({ i - 1 , 1 });
        else
            ++tangerineCount[i - 1];
    }
    for (auto iter = tangerineCount.begin(); iter != tangerineCount.end(); ++iter)
        tangerineCountVec.push_back((*iter).second);
    Sort(tangerineCountVec);

    for (int i{ 0 }; i < tangerineCountVec.size(); ++i)
    {
        k -= tangerineCountVec[i];
        ++answer;
        if (k <= 0)
            return answer;
    }
}

void main()
{
    solution(2, { 1,1,1,1,2,2,2,3 });
}