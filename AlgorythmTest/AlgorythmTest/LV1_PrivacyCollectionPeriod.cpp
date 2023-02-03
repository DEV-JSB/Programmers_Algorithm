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

int GetInt(const char _first, const char _second)
{
    return (_first - "0") * 10 + (_second - "0");
}

int GetLastDay(const string _today, const string _path)
{
    int LastDay = 0;
    int years[2]{ GetInt(_today[2],_today[3]) , GetInt(_path[2],_path[3]) };
    int month[2]{GetInt(_today[5],_today[6]),GetInt(_path[5],_path[6])};
    int day[2]{ GetInt(_today[8],_today[9]),GetInt(_path[8],_path[9]) };

    LastDay = (((years[TODAY] * 12) + month[TODAY]) * 28) + day[TODAY];
    LastDay -= (((years[PATH] * 12) + month[PATH]) * 28) + day[PATH];
    return LastDay;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int termsDay[26]{};
    
    // 하나 이상 존재한다 했으며 privacies 길이가 1 이상이다라고 적혀있어 적용한 예외처리
    if (privacies.size() == 1)
    {
        answer.push_back(1);
        return answer;
    }

    for (int i = 0; i < terms.size(); ++i)
    {
        if (terms[i].length() == 3)
            termsDay[terms[i][0] - "A"] = MONTH_DAY * GetInt("0", terms[i][2]);
        else if (terms[i].length() == 4)
        {
            termsDay[terms[i][0] - "A"] = MONTH_DAY * GetInt(terms[i][2], terms[i][3]);
        }
        else
        {
            termsDay[terms[i][0] - "A"] = 100 * (terms[i][2] - "0");
            termsDay[terms[i][0] - "A"] += 10 * (terms[i][3] - "0");
            termsDay[terms[i][0] - "A"] += (terms[i][4] - "0");
            termsDay[terms[i][0] - "A"] *= 28;

        }
    }

    for (int i = 0; i < privacies.size(); ++i)
    {
        if (GetLastDay(today, privacies[i]) >= termsDay[privacies[i][11] - "A"])
            answer.push_back(i + 1);
    }
    return answer;
}

void main()
{
    solution("2022.05.19", { "A 6","B 12", "C 3" }, { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" });
}