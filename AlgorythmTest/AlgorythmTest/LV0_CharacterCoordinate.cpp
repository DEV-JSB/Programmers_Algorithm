#include <string>
#include <vector>

using namespace std;

#define X 0
#define Y 1

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer{ 0,0 };
    for (string str : keyinput)
    {
        if (str == "right")
        {
            if (answer[X] + 1 <= (board[X] / 2))
                ++answer[X];
        }
        else if (str == "left")
        {
            if (answer[X] - 1 >= -(board[X] / 2))
                --answer[X];
        }
        else if (str == "up")
        {
            if (answer[Y] + 1 <= (board[Y] / 2))
                ++answer[Y];
        }
        else
        {
            if (answer[Y] - 1 >= -(board[Y] / 2))
                --answer[Y];
        }
    }

    return answer;
}