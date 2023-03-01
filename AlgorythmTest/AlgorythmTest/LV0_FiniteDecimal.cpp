#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


bool IsDecimal(const int num)
{
    for (int i = 2; i * i <= num; ++i)
    {
        if (0 == num % i)
            return false;
    }
    return true;
}


int solution(int a, int b) {

    // �� �и� , ���ڰ� ������ ���
    int smallNum = a < b ? a : b;
    // ���̻� ���� �� ���� ���� , ���м��� ����� �����̴�.
    for (int i = 2; i <= smallNum; ++i)
    {
        while (a % i == 0 && b % i == 0)
        {
            a /= i;
            b /= i;
        }
    }
    // b == 1 �� ��� �����̹Ƿ� 1 �� ��ȯ
    if (b == 1)
        return 1;
    for (int i = 2; i <= b; ++i)
    {
        if (b % i == 0 && IsDecimal(i))
        {
            if ((i != 5) && (i != 2))
                return 2;
        }
    }
    return 1;
}
