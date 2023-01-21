#include <string>
#include <vector>

#define MONTH_DAY 28

#define TODAY 0
#define PATH 1

using namespace std;

// trems == 약관의 종류와 약관의 보관 기간을 갖는다.
// 우선 trems 를 통해서 최대 보관 일수를 구하자.

// 날짜들 사이에서의 기간을 구해야 한다.
// 등록했던 날짜 ~ 오늘 날짜
// 오늘 날자 - 현재 날짜 를 하면 되려나?

// 우선 두자리 수를 반환받아야 할듯

int GetInt(char _first, char _second)
{
    return (_first - '0') * 10 + (_second - '0');
}

int GetLastDay(const string _today, const string _path)
{
    int LastDay = 0;
    int years[2]{ GetInt(_today[2],_today[3]) , GetInt(_path[2],_path[3]) };
    int month[2]{GetInt(_today[5],_today[6]),GetInt(_path[5],_path[6])};
    int day[2]{ GetInt(_today[8],_today[9]),GetInt(_path[8],_path[9]) };

    // 연도를 지난 날을 계산한다.
    // 여기서도 예외가 필요하다 무조건 차로 곱하면 안된다.
    // 월은 뺐을때 음수가 되는 경우는 연도 횟수를 차감하면 될듯
    if (month[TODAY] <= month[PATH])
    {
        if(years[TODAY] > years[PATH])
            LastDay += ((years[TODAY] - years[PATH]) - 1) * 12 * MONTH_DAY;
        LastDay += ((month[TODAY] - month[PATH]) + 12) * MONTH_DAY;
    }
    else
    {
        LastDay += ((years[TODAY] - years[PATH])) * 12 * MONTH_DAY;
        LastDay += ((month[TODAY] - month[PATH]) + 1) * MONTH_DAY;
    }
    LastDay -= (MONTH_DAY - day[TODAY]);
    LastDay -= day[PATH];

    return LastDay;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int termsDay[26]{};
    
    for (int i = 0; i < terms.size(); ++i)
    {
        if (terms[i].length() == 3)
            termsDay[terms[i][0] - 'A'] = MONTH_DAY * GetInt('0', terms[i][2]);
        else
            termsDay[terms[i][0] - 'A'] = MONTH_DAY * GetInt(terms[i][2], terms[i][3]);
    }

    for (int i = 0; i < privacies.size(); ++i)
    {
        if (GetLastDay(today, privacies[i]) >= termsDay[privacies[i][11] - 'A'])
            answer.push_back(i + 1);
    }
    return answer;
}

void main()
{
    solution("2022.05.19", { "A 6","B 12", "C 3" }, { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" });
}