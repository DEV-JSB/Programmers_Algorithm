#include <string>
#include <vector>
using namespace std;


long long FiboNacci(int count, int num, long long answer, long long prevNum)
{
    answer += prevNum;
    if (count == num)
        return answer % 1234567;
    return FiboNacci(count + 1, num, answer, (answer - prevNum) % 1234567);
}
long long solution(int n) {
    long long answer;
    answer = FiboNacci(0, n, 0, 1);
    return answer;
}