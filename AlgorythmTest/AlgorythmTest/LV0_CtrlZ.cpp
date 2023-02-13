#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    bool isNegative = false;
    int tmp = 0;
    int prevPlusNum = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '-')
            isNegative = true;
        if ('0' <= s[i] && s[i] <= '9')
        {
            if (s[i] == '0')
                tmp *= 10;
            else
            {
                // 아아아아악!!!!!!!!!!!!!!!!!! 음수계산!!!!!!!!!!!!!!!!!! -3 + 1 은 -2다!!!!!!!!!!!!!!
                /*if (isNegative)
                {
                    tmp *= -1;
                    isNegative = false;
                }*/
                tmp *= 10;
                tmp += s[i] - '0';
            }
        }
        else if (s[i] == ' ')
        {
            if (isNegative)
            {
                tmp *= -1;
                isNegative = false;
            }
            answer += tmp;
            prevPlusNum = tmp;
            tmp = 0;
        }
        else if (s[i] == 'Z')
        {
            answer -= prevPlusNum;
            tmp = 0;
        }
        if (i + 1 == s.length())
        {
            
            answer += isNegative == true ? -tmp : tmp;
        }
    }
    return answer;
}

void main()
{
    solution("-100 -200");
}