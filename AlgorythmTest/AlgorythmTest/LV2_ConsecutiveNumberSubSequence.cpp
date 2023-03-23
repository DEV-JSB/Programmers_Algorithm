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
        for (int j{ 0 }; j < elements.size(); ++j)
        {
            for (int k = 0; k <= i; ++k)
                sum += elements[(j + k) % elements.size()];
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
