#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) 
{
    set<int> set;

    for (int i = 0; i < numbers.size(); ++i)
    {
        for (int j = i + 1; j < numbers.size(); ++j)
        {
            set.insert(numbers[i] + numbers[j]);
        }
    }


    vector<int> answer{set.begin(),set.end()};

    return answer;
}