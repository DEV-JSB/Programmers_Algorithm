#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    int answer = 0;

    // num �� �ڸ����� �˾ƾ� �Ѵ�
    // num �� �ڸ��� ���� �켱 �׳� 1�� �ڸ� �� ���� �˻縦 �Ѵ�
    // ������ ���ؾ� �� �� �ϴ�. 00000 5 �ڸ�° ���ε� , 
    // n��° �ڸ� ���� �ִٸ� x ��°�� 
    // 5 = 1
    // 4 = 2
    // 3 = 3

    // 000000
    // 6 = 1
    // 5 = 2
    // 1 = 6

    // �� n + 1 - x �� ���� �ɱ�?

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