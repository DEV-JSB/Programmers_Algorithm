#include <string>
#include <vector>

using namespace std;

void Sort(vector<int>& numbers)
{
    int tmp;
    for (int i = 0; i < numbers.size() - 1; ++i)
    {
        for (int j = i + 1; j < numbers.size(); ++j)
        {
            if (numbers[i] > numbers[j])
            {
                tmp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = tmp;
            }
        }
    }
}

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int tmp;
    bool pushback = true;
    for (int i = 0; i < numbers.size() - 1; ++i)
    {
        for (int j = i + 1; j < numbers.size(); ++j)
        {
            tmp = numbers[i] + numbers[j];
            for (int k = 0; k < answer.size(); ++k)
            {
                if (tmp == answer[k])
                {
                    pushback = false;
                    break;
                }
                else
                    pushback = true;
            }
            if (pushback)
            {
                answer.push_back(tmp);
                pushback = false;
            }
        }
    }
    Sort(answer);
    return answer;
}
// 2중 FOR 문으로 , 값을 더할 때 마다 비교해서 넣는다?
// -> ㄴㄴ 3중 for 문 오바임

void main()
{
    vector<int> test;
    test.push_back(2);
    test.push_back(1);
    test.push_back(3);
    test.push_back(4);
    test.push_back(1);
    solution(test);


}