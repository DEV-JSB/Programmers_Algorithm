#include <string>
#include <vector>

using namespace std;

string solution(string polynomial) {
    string answer = "";
    int polynomialSum = 0;
    int normalSum = 0;
    int tmp = 0;
    string strtmp;
    for (int i = 0; i < polynomial.size(); ++i)
    {
        // i 가 끝이거나 , 
        // i 다음이 숫자거나
        // i 다음이 공백이거나
        // i 다음이 x 거나 끝.
        if (polynomial[i] >= '0' && polynomial[i] <= '9')
        {
            if (i == polynomial.size() - 1)
            {
                tmp += polynomial[i] - '0';
                normalSum += tmp;
                tmp = 0;
            }
            else if (polynomial[i + 1] == 'x')
            {
                tmp += polynomial[i] - '0';
                polynomialSum += tmp;
                tmp = 0;
                ++i;
            }
            else if (polynomial[i + 1] == ' ')
            {
                tmp += polynomial[i] - '0';
                normalSum += tmp;
                tmp = 0;
                ++i;
            }
            else
            {
                tmp += polynomial[i] - '0';
                tmp *= 10;
            }
        }
        else if (polynomial[i] == 'x')
        {
            ++polynomialSum;
        }
    }
    
    if (polynomialSum)
    {
        while (polynomialSum)
        {
            strtmp += (polynomialSum % 10) + '0';
            polynomialSum /= 10;
        }
        for (int i = strtmp.length() - 1; 0 <= i; --i)
        {
            answer += strtmp[i];
        }
        if (answer == "1")
            answer = "x";
        else
            answer += "x";
    }
   
    if (normalSum)
    {
        if ("" != answer)
            answer += " + ";
        strtmp = "";
        while (normalSum)
        {
            strtmp += (normalSum % 10) + '0';
            normalSum /= 10;
        }
        for (int i = strtmp.length() - 1; 0 <= i; --i)
        {
            answer += strtmp[i];
        }
    }
    
    return answer;
}

void main()
{
    solution("14 + 2 + 1023x + x + 12312");
}