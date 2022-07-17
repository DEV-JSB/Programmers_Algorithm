#include <string>
#include <vector>
#include<list>
using namespace std;


int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    std::list<int> GetDoll;
    int X = board[0].size();
    int Y = board.size();
    // 반복한다 , moves 가 다 끝날 때까지
    for (int i = 0; i < moves.size(); ++i)
    {
        // 탐색을 해야한다 , 0 번째의 열로 쭉 내려가는 형식으로
        for (int y = 0; y < Y; ++y)
        {
            // 만약 ( y,x ) 가 0 이 아니라면 이는 인형이 존재한다는 것.
            if (0 != board[y][moves[i]-1])
            {
                // DollType 는 이전 뽑았던 인형의 정보 만약 같으면 얘는 사라져아함
                if (0 != GetDoll.size()&&GetDoll.back() == board[y][moves[i]-1])
                {
                    ++answer;
                    GetDoll.pop_back();
                }
                else
                    GetDoll.push_back(board[y][moves[i]-1]);
                board[y][moves[i] - 1] = 0;
                break;
            }
        }
    }
    return answer*2;
}

void main()
{
    solution(vector<vector<int>>({ {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} })
    , vector<int>({ 1,5,3,5,1,2,1,4 }));
}