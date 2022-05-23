#include <string>
#include <vector>

using namespace std;

void PushRank(vector<int>& answer, const int count)
{
    switch (count)
    {
    case 6:
        answer.push_back(1);
        break;
    case 5:
        answer.push_back(2);
        break;
    case 4:
        answer.push_back(3);
        break;
    case 3:
        answer.push_back(4);
        break;
    case 2:
        answer.push_back(5);
        break;
    default:
        answer.push_back(6);
        break;

    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int CorrectCount = 0;
    int scrawlCount = 0;

    for (int i = 0; i < 6; ++i)
    {
        if (lottos[i] == 0)
        {
            ++scrawlCount;
            continue;
        }
        for (int j = 0; j < 6; ++j)
        {
            if (lottos[i] == win_nums[j])
            {
                ++CorrectCount;
                break;
            }
        }
    }

    PushRank(answer, CorrectCount + scrawlCount);
    PushRank(answer, CorrectCount);

    return answer;
}
