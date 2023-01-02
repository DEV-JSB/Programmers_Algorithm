#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int tmp = 1;
    for (int i = 1; tmp <= n; ++i)
    {
        tmp *= i;
        ++answer;
    }
    return --answer;
}