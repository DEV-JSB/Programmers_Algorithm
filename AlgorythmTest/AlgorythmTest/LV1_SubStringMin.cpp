#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    
    vector<unsigned long long> t_Nums;
    int answer = 0;
    // p 가 몇 자리 수 인지 분석한다.
    unsigned long long tmp = 0;
    unsigned long long pNum = 0;
    for (int i = 0 ; i < p.length() ; ++i)
    {
        pNum += p[i] - "0";
        pNum *= 10;
    }
    pNum /= 10;

    // p 의 자릿 수 만큼 t 를 나눈다.
    for (int i = 0; i <= t.size() - p.length(); ++i)
    {
        for (int j = i; j < i + p.length(); ++j)
        {
            tmp += t[j] - "0";
            tmp *= 10;
        }
        tmp /= 10;
        t_Nums.push_back(tmp);
        tmp = 0;
    }
    for (int i = 0; i < t_Nums.size(); ++i)
    {
        if (pNum >= t_Nums[i])
            ++answer;
    }
    return answer;
}

void main()
{
    solution("2712", "271");
}