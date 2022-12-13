#include <string>
#include <cstring>

using namespace std;

int solution(string A, string B) {
    int answer = 0;
    if (A == B)
        return 0;
    // A 의 길이만큼 당긴다
    // 1 만큼 당기며 당긴 결과값이 B와 같은지 확인한다
    // 같다면 당긴 횟수를 반환한다
    // 같지 않다면 반복한다
    // 만약 반복한 값이 A의 길이 값 - 1 보다 커진다면 -1을 반환한다

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