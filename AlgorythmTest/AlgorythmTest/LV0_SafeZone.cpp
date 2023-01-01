#include <string>
#include <vector>

using namespace std;


#define Y_NOTUP y != 0
#define Y_NOTDOWN y != board.size() - 1
#define X_NOTLEFT x != 0
#define X_NOTRIGHT x != board[y].size() - 1

int solution(vector<vector<int>> board) {
    int answer = 0;
    // �ڽ��� �ֺ��� ��ź�� �ִ��� ������ Ȯ���ϴ� �˰����� �ʿ��ϴ�.
    // [��][��] �̴�.

    // ���� ���� �����ؼ��� �ȵȴ� , ������ ������ ����� �Ѵ�.


    for (int y = 0; y < board.size(); ++y)
    {
        for (int x = 0; x < board[y].size(); ++x)
        {
            if (Y_NOTDOWN && 1 == board[y + 1][x])
                continue;
            else if (Y_NOTUP && 1 == board[y - 1][x])
                continue;
            else if (X_NOTRIGHT && 1 == board[y][x + 1])
                continue;
            else if (X_NOTLEFT && 1 == board[y][x - 1])
                continue;
            else if (X_NOTRIGHT && Y_NOTDOWN && 1 == board[y + 1][x + 1])
                continue;
            else if (X_NOTLEFT && Y_NOTDOWN && 1 == board[y + 1][x - 1])
                continue;
            else if (X_NOTRIGHT && Y_NOTUP && 1 == board[y - 1][x + 1])
                continue;
            else if (X_NOTLEFT && Y_NOTUP && 1 == board[y - 1][x - 1])
                continue;
            else if (1 == board[y][x])
                continue;
            else
                ++answer;
        }
    }


    return answer;
}