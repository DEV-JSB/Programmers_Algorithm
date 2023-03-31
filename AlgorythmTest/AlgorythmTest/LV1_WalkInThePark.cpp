#include <string>
#include <vector>

using namespace std;


bool IsIgnoreRoute(const vector<string>& park, const int x, const int y,int posX,int posY)
{
    bool isIgnore{ false };
    int willX = x + posX;
    int willY = y + posY;
    if (willX < 0 || willX >= park[0].size())
        return true;
    else if (willY < 0 || willY >= park.size())
        return true;

    willX = x;
    willY = y;

    if (x < 0)
    {
        while (willX)
        {
            if ('X' == park[posY][posX - 1])
                return true;
            ++willX;
            --posX;
        }
    }
    else if (x > 0)
    {
        while (willX)
        {
            if ('X' == park[posY][posX + 1])
                return true;
            --willX;
            ++posX;
        }
    }
    else if (y < 0)
    {
        while (willY)
        {
            if ('X' == park[posY - 1][posX])
                return true;
            ++willY;
            --posY;
        }
    }
    else
    {
        while (willY)
        {
            if ('X' == park[posY + 1][posX])
                return true;
            --willY;
            ++posY;
        }
    }
    return false;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int posX{ -1 };
    int posY{ -1 };
    // 출발점 S 찾음
    for (int y{ 0 }; y < park.size(); ++y)
    {
        for (int x{ 0 }; x < park[y].size(); ++x)
        {
            if (park[y][x] == 'S')
            {
                posX = x;
                posY = y;
                break;
            }
        }
        if (-1 != posX || -1 != posY)
            break;
    }
    // STR 값 토대로 이동할 방향 int 에 저장
    for (string str : routes)
    {
        int willMoveX{ 0 };
        int willMoveY{ 0 };
        int distance = str[2] - '0';
        if (str[0] == 'E')
            willMoveX = 1 * distance;
        else if (str[0] == 'W')
            willMoveX = -1 * distance;
        else if (str[0] == 'S')
            willMoveY = 1 * distance;
        else
            willMoveY = -1 * distance;
        if (IsIgnoreRoute(park, willMoveX, willMoveY, posX, posY))
            continue;
        posX += willMoveX;
        posY += willMoveY;
    }
    answer.push_back(posY);
    answer.push_back(posX);
    return answer;
}

void main()
{
    solution({ {"OSO"},{"OOO"},{"OXO"},{"OOO"} }, { "E 2","S 3","W 1" });
}