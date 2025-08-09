#include <string>
#include <vector>
#include <stack>
using namespace std;
#include <string>
#include <vector>
#include <stack>
using namespace std;


string solution(int n, int k, vector<string> cmd)
{
    string answer = "";
    vector<int> graph;
    stack<pair<int, int>> trashUpDown;
    stack<int> trashIndex;
    int nowIndex = k;
    graph.resize(n, 1);

    vector<int> up;
    vector<int> down;

    up.resize(n + 2, 0);
    down.resize(n + 2, 0);

    for (int i = 0; i < n; ++i)
    {
        up[i + 1] = i - 1;
        down[i + 1] = i + 1;
    }



    for (int i = 0; i < cmd.size(); ++i)
    {
        int nowIndexCorrect = nowIndex + 1;
        char command = cmd[i][0];
        switch (command)
        {
        case 'U':
        {
            int size = stoi(cmd[i].substr(2));
            for (int j = 0; j < size; ++j)
            {
                nowIndex = up[nowIndexCorrect];
                nowIndexCorrect = nowIndex + 1;
            }
        }
            break;
        case 'D':
            int size = stoi(cmd[i].substr(2));
            for (int j = 0; j < size; ++j)
            {
                nowIndex = down[nowIndexCorrect];
                nowIndexCorrect = nowIndex + 1;
            }
            break;
        case 'Z':
        {
            graph[trashIndex.top()] = 1;
            pair<int, int> trashedUpDown = trashUpDown.top();
            down[trashedUpDown.first + 1] = trashIndex.top();
            up[trashedUpDown.second + 1] = trashIndex.top();

            trashUpDown.pop();
            trashIndex.pop();
            break;
        }
        case 'C':
            graph[nowIndex] = 0;

            trashIndex.push(nowIndex);
            trashUpDown.push(make_pair(up[nowIndexCorrect], down[nowIndexCorrect]));

            down[up[nowIndexCorrect] + 1] = down[nowIndexCorrect];
            up[down[nowIndexCorrect] + 1] = up[nowIndexCorrect];
            nowIndex = down[nowIndexCorrect] < n ? down[nowIndexCorrect] : up[nowIndexCorrect];
            break;
        }
    }

    for (int i = 0; i < graph.size(); ++i)
    {
        answer.push_back(graph[i] > 0 ? 'O' : 'X');
    }

    return answer;
}

void main()
{
    int n = 8;
    int k = 2;
    vector<string> cmd = { "D 2","C","U 3","C","D 4","C" , "U 2" , "Z" , "Z" , "U 1","C" };

    string result = solution(n, k, cmd);
}
void main()
{
    solution(5, 3, { "U 3","C" }); // "OOOXO"


}