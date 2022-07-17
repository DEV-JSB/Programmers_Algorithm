#include <string>
#include <vector>
#include<list>
using namespace std;


int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    std::list<int> GetDoll;
    int X = board[0].size();
    int Y = board.size();
    // �ݺ��Ѵ� , moves �� �� ���� ������
    for (int i = 0; i < moves.size(); ++i)
    {
        // Ž���� �ؾ��Ѵ� , 0 ��°�� ���� �� �������� ��������
        for (int y = 0; y < Y; ++y)
        {
            // ���� ( y,x ) �� 0 �� �ƴ϶�� �̴� ������ �����Ѵٴ� ��.
            if (0 != board[y][moves[i]-1])
            {
                // DollType �� ���� �̾Ҵ� ������ ���� ���� ������ ��� ���������
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