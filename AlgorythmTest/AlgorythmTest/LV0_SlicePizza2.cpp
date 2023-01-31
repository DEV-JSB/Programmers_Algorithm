#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    // n 을 곱해서 6 에 나눠떨어진다면 해당 값이 최소
    while ((answer * 6) % n != 0)
        ++answer;
    return answer;
}