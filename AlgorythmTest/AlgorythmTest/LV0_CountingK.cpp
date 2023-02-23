#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer{};
    int tmp{};
    for (int num{ i }; num <= j; ++num)
    {
        tmp = num;
        while (tmp)
        {
            int remain{ tmp % 10 };
            if (remain == k)
                ++answer;
            tmp /= 10;
        }
    }
    return answer;
}