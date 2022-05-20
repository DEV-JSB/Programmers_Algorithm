#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int sign;
    int startpivot = 0;
    if (s[0] == '-')
    {
        sign = -1;
        startpivot = 1;
    }
    else if (s[0] == '+')
    {
        sign = 1;
        startpivot = 1;
    }
    for (int i = startpivot; i < s.length(); ++i)
    {

        answer += (int)(s[i] - '0');
        if(!(i == s.length()-1))
            answer *= 10;
    }

    return sign * answer;
}
