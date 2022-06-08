#include <string>
#include <vector>

using namespace std;

void Bubblesort(vector<int>& part)
{
    if (part.size() <= 1)
        return;
    int temp;
    for (int i = part.size(); i > 0; --i)
    {
        for (int j = 0; j < i-1; ++j)
        {
            if (part[j] > part[j + 1])
            {
                temp = part[j];
                part[j] = part[j + 1];
                part[j + 1] = temp;
            }

        }
    }
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> part;
    // 배열을 잘라야 한다. 주어진 commands 만큼
    // 잘라야할 필요가 있을까? ㅇㅇ 정렬해야함
    for (int i = 0; i < commands.size(); ++i)
    {
        for (int j = commands[i][0] - 1; j < commands[i][1]; ++j)
        {
            part.push_back(array[j]);
        }
        Bubblesort(part);
        answer.push_back(part[commands[i][2] - 1]);
        part.clear();
    }
    return answer;
}

void main()
{
    vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
    vector<vector<int>> commands = { {2,5,3},{4,4,1},{1,7,3} };
    solution(array, commands);
}