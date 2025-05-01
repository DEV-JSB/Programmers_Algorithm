#include <string>
#include <vector>

using namespace std;



int solution(vector<vector<string>> board, int h, int w) 
{
    int answer = 0;
    int width = board[0].size();
    int height = board.size();

    string word = board[h][w];
    answer += h - 1 < 0 ? 0 : board[h - 1][w] == word;
    answer += h + 1 >= height ? 0 : board[h + 1][w] == word;
    answer += w - 1 < 0 ? 0 : board[h][w - 1] == word;
    answer += w + 1 >= width ? 0 : board[h][w + 1] == word;


    return answer;
}

int solution2(vector<vector<string>> board, int h, int w)
{
    int answer = 0;
    int width = board[0].size();
    int height = board.size();

    int direction[4][2]{ {1,0},{-1,0},{0,1},{0,-1} };

    string word = board[h][w];
    for (int i = 0; i < 4; ++i)
    {
        int checkPosX = w + direction[i][1];
        int checkPosY = h + direction[i][0];
        if (checkPosX < 0 || checkPosY < 0 || checkPosX >= width || checkPosY >= height)
        {
            continue;
        }
        answer += word == board[checkPosY][checkPosX];
    }

    return answer;

}

void main()
{
    solution2({
        {"blue", "red", "orange", "red"},
        {"red", "red", "blue", "orange"},
        {"blue", "orange", "red", "red"},
        {"orange", "orange", "red", "blue"}
        }, 1, 1);
}