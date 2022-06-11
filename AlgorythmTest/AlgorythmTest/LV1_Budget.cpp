#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

void BubbltSort(vector<int>& arr)
{
    int tmp;
    for (int i = arr.size() - 1; i >= 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[i] < arr[j])
            {
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
}

int solution(vector<int> d, int budget) {
    int answer = 0;
    int sum = 0;
    int sumcount = 0;
    BubbltSort(d);

    for (size_t i = 0; i < d.size(); ++i)
    {
        // ������ �Ѱ��� �μ��� ���� ������ , ī��Ʈ��
        // ���� �̸� i ������ ����
        sum += d[i];

        if (sum <= budget)
            ++sumcount;
        else
            break;
    }

    return answer = sumcount;
}