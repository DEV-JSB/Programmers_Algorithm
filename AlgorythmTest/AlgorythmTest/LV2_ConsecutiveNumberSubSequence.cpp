#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> elements) {
    int answer{ 0 };
    unordered_map<int, int> sums;
    for (int i{ 0 }; i < elements.size(); ++i)
    {
        int sum{ 0 };
        int sumCount = i;
        for (int j{ 0 }; j < elements.size(); ++j)
        {
            for (int k = 0; k <= sumCount; ++k)
            {
                if (j + k >= elements.size())
                    sum += elements[(j + k) % elements.size()];
                else
                    sum += elements[j + k];
            }
            if (sums.find(sum) == sums.end())
            {
                sums.insert({ sum,sum });
                ++answer;
            }
            sum = 0;
        }
    }
    return answer;
}

void main()
{
    solution({ 7,9,1,1,4 });
}