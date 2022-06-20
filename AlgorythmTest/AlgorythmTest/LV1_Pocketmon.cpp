#include <vector>
#include<algorithm>
#include<cmath>
using namespace std;


int solution(vector<int> nums)
{
    std::sort(nums.begin(), nums.end());
    int ChooseCount = nums.size() / 2;
    int TypeCount = 0;
    int RecentNum = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (RecentNum != nums[i])
        {
            RecentNum = nums[i];
            ++TypeCount;
        }
    }
    return (TypeCount < ChooseCount) ? TypeCount : ChooseCount;
}

void main()
{
    vector<int>arr = { 3,3,3,2,2,2 };
    solution(arr);
}