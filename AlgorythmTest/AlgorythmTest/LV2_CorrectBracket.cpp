#include<string>
#include <iostream>

using std::string;

//()((()))()()()(())(()()()())
//(())()()(
//�������� �������Ѵ�.
// ���� ���� ��ŭ ���� ���;� �Ѵ�!!

// �ƴѵ� (()()) �̰� ��¿����
// (()()((())))
// (()(())())
// 0011 001011
// (()) (()())
// 001011
// (()())
// (()())((()))()()(())
// 00101100011101010011
// 0010110001
// 1100101011
// Ȯ���Ѱ� ���� ������ ���� ������ ������ ���ƾ� �Ѵ�.
// ������ ������ ( �� �����ؾ��Ѵ�.
// ������ 1���� �ʰ� �ϰ� ������ ������ ��
bool solution(string s)
{
    if (")" == s[0])
        return false;
    bool bAnswer;
    int openCount = 0;
    int closeCount = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == "(")
            ++openCount;
        else
            --openCount;
        // �켱 �ݴ� ������ ���� ���� ������ ���� �� ����
        if (openCount < 0)
            return false;
    }
    if (0 != openCount)
        return false;
    else
        return true;
}