#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer{ 0 };
    string binaryStr{ "" };
    bool translateSuccess{ false };
    while (n)
    {
        binaryStr += '0' + n % 2;
        n /= 2;
    }
    for (int i{ 0 }; i < binaryStr.size(); ++i)
    {
        if ('0' == binaryStr[i])
        {
            translateSuccess = true;
            break;
        }
    }
    if (translateSuccess)
    {
        for (int i{ 0 }, num{ 1 }; i < binaryStr.size(); ++i, num *= 2)
        {
            if ('1' == binaryStr[i] && n - num > n)
            {
                return n - num + 1;
            }
            answer += num * (binaryStr[i] == '1' ? 1 : 0);
        }
    }
    else
    {
        ++answer;
        for (int i{ 0 }, num{ 2 }; i < binaryStr.size(); ++i, num *= 2)
        {
            if (i == binaryStr.size() - 2)
                continue;
            answer += num * (binaryStr[i] == '1' ? 1 : 0);
        }
    }
    
    return answer;
}