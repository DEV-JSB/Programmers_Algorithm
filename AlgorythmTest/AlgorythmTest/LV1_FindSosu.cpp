#include <string>
#include <vector>
#include<math.h>
using namespace std;

int solution(int n) {
    vector<int>sosu;
    sosu.push_back(2);
    sosu.push_back(3);
    if (2 == n)
        return 1;
    else if (3==n)
        return 2;
    int answer = 2;
    int count = 0;
    for (int i = 5; i <= n; i += 2)
    {
        for (int j = 0; sosu[j]<=sqrt(i); ++j)
        {
            if (i % sosu[j] == 0)
            {
                ++count;
                break;
            }
        }
        if (count)
        {
            count = 0;
            continue;
        }
        else
        {
            sosu.push_back(i);
            ++answer;
        }
    }
    return answer;
}
