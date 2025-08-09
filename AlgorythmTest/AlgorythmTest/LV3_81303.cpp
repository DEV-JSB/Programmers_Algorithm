#include <string>
#include <vector>
#include <stack>
using namespace std;


string solution(int n, int k, vector<string> cmd)
{
    string answer = "";
    stack<int> deletedIndex;

    vector<int> up;
    vector<int> down;

    for (int i = 0; i < n + 1; ++i)
    {
        up.push_back(i - 1);
        down.push_back(i + 1);
    }

    ++k;

    for (int i = 0; i < cmd.size(); ++i)
    {
        char command = cmd[i][0];
        switch (command)
        {
        case 'U':
        {
            int size = stoi(cmd[i].substr(2));
            for (int j = 0; j < size; ++j)
            {
                k = up[k];
            }
        }
        break;
        case 'D':
        {
            int size = stoi(cmd[i].substr(2));
            for (int j = 0; j < size; ++j)
            {
                k = down[k];
            }
        }
        break;

        case 'Z':
        {
            down[up[deletedIndex.top()]] = deletedIndex.top();
            up[down[deletedIndex.top()]] = deletedIndex.top();
            deletedIndex.pop();
            break;
        }
        case 'C':
            deletedIndex.push(k);
            down[up[k]] = down[k];
            up[down[k]] = up[k];
            k = down[k] <= n ? down[k] : up[k];
            break;
        }
    }

    answer.append(n, 'O');

    while (!deletedIndex.empty())
    {
        answer[deletedIndex.top() - 1] = 'X';
        deletedIndex.pop();
    }

    return answer;
}