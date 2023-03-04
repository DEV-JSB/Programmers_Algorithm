#include <string>
#include <vector>

using namespace std;

#define TOP 0
#define LEFT 1
#define BTM 2
#define RIGHT 3
vector<int> solution(vector<string> wallpaper) {
    vector<int> answer{ 50,50,0,0 };
    for (int y{ 0 } ; y < wallpaper.size(); ++y)
    {
        for (int x{ 0 }; x < wallpaper[y].length(); ++x)
        {
            if (wallpaper[y][x] == '#')
            {
                if (answer[LEFT] > x)
                    answer[LEFT] = x;
                if (answer[RIGHT] < x)
                    answer[RIGHT] = x;
                if (answer[TOP] > y)
                    answer[TOP] = y;
                if (answer[BTM] < y)
                    answer[BTM] = y;
            }
        }
    }
    ++answer[BTM];
    ++answer[RIGHT];
    return answer;
}