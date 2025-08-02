#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) 
{
    int answer = 0;
    stack<int> bucket;

    vector<stack<int>> stackBoard;

    int size = board.size();
    stackBoard.resize(size);
    for (int y = size - 1; y >= 0; --y)
    {
        for (int x = 0; x < size; ++x)
        {
            int value = board[y][x];
            if (value != 0)
            {
                stackBoard[x].push(value);
            }
        }
    }

    for (int i = 0; i < moves.size(); ++i)
    {
        int moveIndex = moves[i] - 1;
        if (stackBoard[moveIndex].size() == 0)
        {
            continue;
        }
        int pullUpNum = stackBoard[moveIndex].top();
        stackBoard[moveIndex].pop();

        if (!bucket.empty() && bucket.top() == pullUpNum)
        {
            bucket.pop();
            ++answer;
        }
        else
        {
            bucket.push(pullUpNum);
        }
    }
    return answer * 2;
}

void main()
{
    vector<vector<int>> board = {
            {0, 0, 0, 0, 0},
            {0, 0, 1, 0, 3},
            {0, 2, 5, 0, 1},
            {4, 2, 4, 4, 2},
            {3, 5, 1, 3, 1}
    };

    vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4 };

    int result = solution(board, moves);
}