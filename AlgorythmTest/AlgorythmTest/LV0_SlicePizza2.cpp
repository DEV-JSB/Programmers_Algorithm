#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    // n �� ���ؼ� 6 �� �����������ٸ� �ش� ���� �ּ�
    while ((answer * 6) % n != 0)
        ++answer;
    return answer;
}