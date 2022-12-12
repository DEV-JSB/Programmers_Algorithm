#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    int answer = 0;

    // A 의 길이만큼 당긴다
    // 1 만큼 당기며 당긴 결과값이 B와 같은지 확인한다
    // 같다면 당긴 횟수를 반환한다
    // 같지 않다면 반복한다
    // 만약 반복한 값이 A의 길이 값 - 1 보다 커진다면 -1을 반환한다

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