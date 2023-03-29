#include <string>
#include <vector>
using namespace std;
vector<int> solution(vector<int> numbers)
{
    vector<int> answer;
    bool findBigNum{ false };
    int duplicationCount{ 0 };
    for (size_t i{ 0 }; i < numbers.size() - 1; ++i)
    {
        findBigNum = false;
        duplicationCount = 0;
        while (numbers[i] == numbers[i + 1])
        {
            if (i + 1 == numbers.size() - 1)
            {
                for (int j{ 0 }; j < duplicationCount + 1; ++j)
                    answer.push_back(-1);
                i = numbers.size();
                findBigNum = true;
                break;
            }
            ++duplicationCount;
            ++i;
        }
        for (size_t j{ i + 1 }; j < numbers.size(); ++j)
        {
            if (numbers[i] < numbers[j])
            {
                findBigNum = true;
                if (duplicationCount != 0)
                {
                    for (int i{ 0 }; i <= duplicationCount; ++i)
                        answer.push_back(numbers[j]);
                }
                else
                    answer.push_back(numbers[j]);
                break;
            }
        }
        if (false == findBigNum)
            answer.push_back(-1);
    }
    answer.push_back(-1);
    return answer;
}