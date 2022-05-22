#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    
    int Max, Min;
    if (sizes[0][0] < sizes[0][1])
    {
        Max = sizes[0][1];
        Min = sizes[0][0];
    }
    else
    {
        Max = sizes[0][0];
        Min = sizes[0][1];
    }
    for (int i = 1; i < sizes.size(); ++i)
    {
        if (sizes[i][0] <= sizes[i][1])
        {
            if (Max < sizes[i][1])
                Max = sizes[i][1];
            if (Min < sizes[i][0])
                Min = sizes[i][0];
        }
        else
        {
            if (Max < sizes[i][0])
                Max = sizes[i][0];
            if (Min < sizes[i][1])
                Min = sizes[i][1];
        }
    }
    return Max * Min;
}

void main()
{
    vector<vector<int>> test = { {60,50},{30,70},{60,30},{80,40} };
    solution(test);
}