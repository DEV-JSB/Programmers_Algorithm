#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    int size = s.length();
    if (!(size == 4 || size == 6))
        return false;
    // 문자가 4 또는 6.
    // 숫자로만 구성
    for (int i = 0; i < size; ++i)
    {
        if (!('0' <= s[i] && s[i] <= '9'))
            return false;
    }
    return true;
}