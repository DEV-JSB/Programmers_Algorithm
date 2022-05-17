#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    int num = 0;
    while (n)
    {
        num = n % 10;
        n /= 10;
        answer.push_back(num);
    }
    return answer;
}