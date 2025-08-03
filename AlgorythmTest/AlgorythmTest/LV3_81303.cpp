#include <string>
#include <vector>
#include <stack>
using namespace std;

int MoveInGraph(vector<int>& graph, char dir, int distance, int nowIndex)
{
    int move = 1;
    int value;
    int movedIndex = 0;
    while (distance > 0)
    {
        movedIndex = dir == 'U' ? nowIndex - move : nowIndex + move;
        move++;
        if (graph[movedIndex] == 0)
        {
            continue;
        }
        distance--;
    }
    return movedIndex;
}

int FindDownStack(const vector<int>& graph, int nowIndex)
{
    int upIndex = nowIndex;
    while (graph[upIndex] == 0)
    {
        upIndex--;
        if (upIndex < 0)
        {
            upIndex = 0;
            break;
        }
    }

    while (graph[nowIndex] == 0)
    {
        nowIndex++;
        if (nowIndex >= graph.size())
        {
            return upIndex;
        }
    }
    
    return nowIndex;
}


string solution(int n, int k, vector<string> cmd) 
{
    string answer = "";
    vector<int> graph;
    stack<int> trashStack;
    int nowIndex = k;
    graph.resize(n, 1);

    for (int i = 0; i < cmd.size(); ++i)
    {
        char command = cmd[i][0];
        switch (command)
        {
        case 'U':
        case 'D':
            nowIndex = MoveInGraph(graph, command, cmd[i][2] - '0', nowIndex);
            break;
        case 'Z':
            graph[trashStack.top()] = 1;
            trashStack.pop();
            break;
        case 'C':
            graph[nowIndex] = 0;
            trashStack.push(nowIndex);
            nowIndex = FindDownStack(graph, nowIndex);
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
    vector<string> cmd = { "D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z" };

    string result = solution(n, k, cmd);
}