#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    int length = 1;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == ' ') // ���ڿ��� �����϶�
        {
            length = 1;
            continue;
        }
        else if(length % 2 == 1) // ���ڿ��� ¦������ , a~z �϶�
        {
            if ('a' <= s[i] && s[i] <= 'z')
                s[i] -= 32;
        }
        else // ���ڿ��� Ȧ���̰� A~Z �϶�
        {
            if ('A' <= s[i] && s[i] <= 'Z')
                s[i] += 32;
        }
        ++length;
    }

    return s;
}

