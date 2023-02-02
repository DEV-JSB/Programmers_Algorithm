#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    int order = 1;
    for (int i = 0; i < emergency.size(); ++i)
    {
        order = 1;
        for (int j = 0 ; j < emergency.size() ; ++j)
        {
            if (emergency[i] < emergency[j])
                ++order;
        }
        answer.push_back(order);
    }

    return answer;
}