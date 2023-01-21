#include <string>
#include <vector>

#define MONTH_DAY 28

#define TODAY 0
#define PATH 1

using namespace std;

// trems == ����� ������ ����� ���� �Ⱓ�� ���´�.
// �켱 trems �� ���ؼ� �ִ� ���� �ϼ��� ������.

// ��¥�� ���̿����� �Ⱓ�� ���ؾ� �Ѵ�.
// ����ߴ� ��¥ ~ ���� ��¥
// ���� ���� - ���� ��¥ �� �ϸ� �Ƿ���?

// �켱 ���ڸ� ���� ��ȯ�޾ƾ� �ҵ�

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

    // ������ ���� ���� ����Ѵ�.
    // ���⼭�� ���ܰ� �ʿ��ϴ� ������ ���� ���ϸ� �ȵȴ�.
    // ���� ������ ������ �Ǵ� ���� ���� Ƚ���� �����ϸ� �ɵ�
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