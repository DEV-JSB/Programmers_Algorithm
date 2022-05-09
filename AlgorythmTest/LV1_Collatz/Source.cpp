#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    int Count = 0;
    // 횟수가 500을 넘거나 , 결과가 1이 될 떄 까지반복
    while (1)
    {
        if (num == 1)
            return Count;
        else if (Count >= 500)
            return -1;
        // 입력된 수가 짝수라면 2 로 나눈다
        if (num % 2 == 0)
        {
            num /= 2;
        }
        // 입력된 수가 홀수라면 3을 곱하고 1을 더한다.
        else if (num % 2 == 1)
        {
            num *= 3;
            ++num;
        }
        ++Count;
    }
}