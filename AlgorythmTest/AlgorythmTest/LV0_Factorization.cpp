#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    bool numIsDecimal = true;
    bool isDecimal = false;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            numIsDecimal = false;
            isDecimal = true;
            for (int j = 2; j * j <= i; ++j)
            {
                if (i % j == 0)
                {
                    isDecimal = false;
                    break;
                }
            }
            if (isDecimal)
                answer.push_back(i);
        }
    }
    if (numIsDecimal)
        answer.push_back(n);


    return answer;
}
