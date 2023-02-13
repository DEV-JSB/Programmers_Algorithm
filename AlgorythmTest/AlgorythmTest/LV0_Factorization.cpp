#include <string>
#include <vector>

using namespace std;

bool IsDecimal(const int num)
{
    bool isDecimal = true;
    for (int i = 2; i * i <= num; ++i)
    {
        if (i == 2 || i == 3 || i == 5 || i == 7)
            return true;
        if (num % i == 0)
        {
            return false;
            break;
        }
    }
    return true;
}

vector<int> solution(int n) {
    vector<int> answer;
    int num = n; 
    int lastDecimal = 0;
    for (int i = 2; i * i <= num; ++i)
    {
        if (IsDecimal(i) && num % i == 0)
        {
            lastDecimal = i;
            answer.push_back(i);
            while (num % i == 0)
                num /= i;
        }
    }
    
    if (IsDecimal(n) && answer.size() == 0)
        answer.push_back(n);
    else if(IsDecimal(num) && num > lastDecimal)
        answer.push_back(num);
    

    return answer;
}
