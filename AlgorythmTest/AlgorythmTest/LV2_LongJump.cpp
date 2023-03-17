#include <string>
#include <vector>
using namespace std;


int FiboNachi(int count, int num, int answer, int prevNum)
{
    answer += prevNum;
    answer %= 1234567;
    if (count == num)
        return answer;
    FiboNachi(count + 1, num, answer, answer - prevNum);
}
int solution(int n) {
    return FiboNachi(0, n, 0, 1);
}
