#include <string>
#include <vector>

using namespace std;

int GetCorrectCount(const vector<int>& pattern, const vector<int>& answers);

struct Student
{
    vector<int> m_vPattern;
    int m_iCorrectCount;
};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    Student st[3];
    int Max = 0;

    st[0].m_vPattern = { 1, 2, 3, 4, 5 };
    st[0].m_iCorrectCount = (GetCorrectCount(st[0].m_vPattern, answers));
    st[1].m_vPattern = { 2,1,2,3,2,4,2,5 };
    st[1].m_iCorrectCount = (GetCorrectCount(st[1].m_vPattern, answers));
    st[2].m_vPattern = { 3,3,1,1,2,2,4,4,5,5 };
    st[2].m_iCorrectCount = (GetCorrectCount(st[2].m_vPattern, answers));

    for (int i = 0; i < 3; ++i)
    {
        if (st[i].m_iCorrectCount > Max)
            Max = st[i].m_iCorrectCount;
    }

    for (int i = 0; i < 3; ++i)
    {
        if (Max == st[i].m_iCorrectCount)
            answer.push_back(i + 1);
    }

    return answer;
}

int GetCorrectCount(const vector<int>& pattern, const vector<int>& answers)
{
    int correctcount = 0;
    for (int i = 0, j = 0; i < answers.size(); ++i, ++j)
    {
        if (j == pattern.size())
            j = 0;
        if (pattern[j] == answers[i])
            ++correctcount;
    }
    return correctcount;
}
