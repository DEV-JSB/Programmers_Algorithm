#include<vector>
#include <map>
using namespace std;


void DFS(int coast,const vector<vector<int>>& maps, const vector<int> destination,const int x,const int y,int& answer
    ,vector<vector<bool>>& isPassed)
{
    if (x < 0 || y < 0 || x > destination[0] || y > destination[1])
        return;
    else if (isPassed[y][x])
        return;
    else if (maps[y][x] == 0)
        return;
    isPassed[y][x] = true;
    coast += maps[y][x];
    if (x == destination[0] && destination[1] == y)
    {
        if (0 == answer)
            answer = coast;
        else
            answer = answer > coast ? coast : answer;
        return;
    }

    DFS(coast, maps, destination, x , y + 1, answer, isPassed);
    DFS(coast, maps, destination, x + 1, y, answer, isPassed);
    DFS(coast, maps, destination, x, y - 1, answer, isPassed);
    DFS(coast, maps, destination, x - 1, y, answer, isPassed);
}


int solution(vector<vector<int> > maps)
{
    vector<vector<bool>> isPassed;
    isPassed.resize(maps.size());
    for (size_t i{ 0 }; i < maps[0].size(); ++i)
        isPassed[i].resize(maps[0].size());
    int answer = 0;
    DFS(0, maps, { (int)maps[0].size() - 1 , (int)maps.size() - 1 }, 0, 0,answer, isPassed);
    if (0 == answer)
        return -1;
    return answer;
}
void main()
{
    solution({ {1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1} });
}