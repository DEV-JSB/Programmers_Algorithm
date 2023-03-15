#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> tangerineCount;
    
    for (int i : tangerine)
    {
        if (tangerineCount.find(i - 1) == tangerineCount.end())
            tangerineCount.insert({ i - 1 , 1 });
        else
            ++tangerineCount[i - 1];
    }
    while (true)
    {
        int maxCountIndex{ (*tangerineCount.begin()).first };
        for (auto iter = tangerineCount.begin(); iter != tangerineCount.end(); ++iter)
        {
            if (tangerineCount[maxCountIndex] < (*iter).second)
                maxCountIndex = (*iter).first;
            else if (tangerineCount[maxCountIndex] == (*iter).second)
            {
                if ((*iter).first > maxCountIndex)
                    maxCountIndex = (*iter).first;
            }
        }
        k -= tangerineCount[maxCountIndex];
        tangerineCount.erase(maxCountIndex);
        ++answer;
        if (k <= 0)
            return answer;
    }
    return answer;
}

void main()
{
    solution(6, { 1,3,2,5,4,5,2,3 });
}