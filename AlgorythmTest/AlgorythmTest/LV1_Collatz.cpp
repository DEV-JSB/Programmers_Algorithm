#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    int Count = 0;
    // Ƚ���� 500�� �Ѱų� , ����� 1�� �� �� �����ݺ�
    while (1)
    {
        if (num == 1)
            return Count;
        else if (Count >= 500)
            return -1;
        // �Էµ� ���� ¦����� 2 �� ������
        if (num % 2 == 0)
        {
            num /= 2;
        }
        // �Էµ� ���� Ȧ����� 3�� ���ϰ� 1�� ���Ѵ�.
        else if (num % 2 == 1)
        {
            num *= 3;
            ++num;
        }
        ++Count;
    }
}