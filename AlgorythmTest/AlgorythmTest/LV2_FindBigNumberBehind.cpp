#include <string>
#include <vector>
using namespace std;
vector<int> solution(vector<int> numbers) 
{
    vector<int> answer;
    bool findBigNum{ false };
    for (size_t i{ 0 }; i < numbers.size() - 1; ++i)
    {
        findBigNum = false;
        for (size_t j{ i + 1 }; j < numbers.size(); ++j)
        {
            if (numbers[i] < numbers[j])
            {
                findBigNum = true;
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
void main()
{
    solution({ 2,3,3,5 });
}