#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    int answer = 0;

    // A �� ���̸�ŭ ����
    // 1 ��ŭ ���� ��� ������� B�� ������ Ȯ���Ѵ�
    // ���ٸ� ��� Ƚ���� ��ȯ�Ѵ�
    // ���� �ʴٸ� �ݺ��Ѵ�
    // ���� �ݺ��� ���� A�� ���� �� - 1 ���� Ŀ���ٸ� -1�� ��ȯ�Ѵ�

    for (int i = 0; i < A.length(); ++i)
    {
        char firstWord = A[A.length() - 1];
        strncpy(A[0], B.c_str(), A.length() - 1);
        for (int j = 0; j < A.length() - 1; ++j)
            A[j + 1] = A[j];
        A[0] = firstWord;

        if (A == B)
            return i + 1;
    }


    return -1;
}


void main()
{
    solution("hello", "ohell");
}