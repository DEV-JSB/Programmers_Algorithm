#include <string>
#include <cstring>

using namespace std;

int solution(string A, string B) {
    int answer = 0;
    if (A == B)
        return 0;
    // A �� ���̸�ŭ ����
    // 1 ��ŭ ���� ��� ������� B�� ������ Ȯ���Ѵ�
    // ���ٸ� ��� Ƚ���� ��ȯ�Ѵ�
    // ���� �ʴٸ� �ݺ��Ѵ�
    // ���� �ݺ��� ���� A�� ���� �� - 1 ���� Ŀ���ٸ� -1�� ��ȯ�Ѵ�

    char* char_A = new char[A.length()];
    strcpy(char_A, A.c_str());
    for (int i = 0; i < A.length() - 1; ++i)
    {
        strncpy(char_A + 1, A.c_str(), A.length() - 1);
        char_A[0] = A[A.length() - 1];
        A = char_A;
        if (!strcmp(char_A, B.c_str()))
            return i + 1;
    }


    return -1;
}


void main()
{
    solution("rainbowsix", "xrainbowsi");
}