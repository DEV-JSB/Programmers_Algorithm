#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int divisor;
    int multiple;

    for (int i = 1; i <= n; ++i)
    {
        if (m % i == 0 && n % i == 0)
            divisor = i;
    }
    for (int i = m * n; i >= m; i -= m)
    {
        if (i % n == 0)
            multiple = i;
    }
    answer.push_back(divisor);
    answer.push_back(multiple);
    return answer;
}
