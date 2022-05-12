#include <vector>
#include <iostream>
using namespace std;

int decimalcheck(int a)
{
    for (int i = 2; i < a; ++i)
    {
        if (a % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int solution(vector<int> nums) {
    int answer = 0;
    int sum = 0;

    for (int i = 0; i < nums.size() - 2; ++i)
    {
        sum = 0;

        for (int j = i + 1; j < nums.size() - 1; ++j)
        {
            for (int k = j + 1; k < nums.size(); ++k)
            {
                sum = nums[i] + nums[j] + nums[k];
                if (decimalcheck(sum))
                    ++answer;
            }
        }
    }
    return answer;
}

void main()
{
    vector<int>test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(6);
    test.push_back(7);
    test.push_back(4);

    cout << solution(test);
}