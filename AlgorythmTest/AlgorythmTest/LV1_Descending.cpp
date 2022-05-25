#include <string>
#include <vector>

using namespace std;

void Descending(vector<int>& nums);

long long solution(long long n) {
    long long answer = 0;
    vector<int>nums;
    while (n)
    {
        nums.push_back(n % 10);
        n /= 10;
    }

    Descending(nums);

    for (int i = 0; i < nums.size(); ++i)
    {
        answer += nums[i];
        if (i == nums.size() - 1)
            break;
        answer *= 10;
    }
    return answer;
}

void Descending(vector<int>& nums)
{
    int tmp;
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (nums[i] < nums[j])
            {
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    }
}
