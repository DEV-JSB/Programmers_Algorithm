#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    int answer = 0;

    // num 의 자릿수를 알아야 한다
    // num 의 자릿수 보다 우선 그냥 1의 자리 수 부터 검사를 한다
    // 역수를 취해야 할 듯 하다. 00000 5 자리째 수인데 , 
    // n번째 자리 수가 있다면 x 번째는 
    // 5 = 1
    // 4 = 2
    // 3 = 3

    // 000000
    // 6 = 1
    // 5 = 2
    // 1 = 6

    // 즉 n + 1 - x 가 답인 걸까?

    if (0 == num && 0 == k)
        return 1;
    else if (0 == num)
        return -1;
    int numCount = 1;
    int pos = 0;
    while (0 < num)
    {
        if (num % 10 == k)
            pos = numCount;
        num /= 10;
        ++numCount;
    }
    return pos == 0 ? -1 : numCount - pos;
}