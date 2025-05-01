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