#include <string>
#include <vector>
#include <math.h>   
using namespace std;

int solution(vector<vector<int>> dots) {
    vector<float> parallels;
    for (int i = 0; i < dots.size()-1 ; ++i)
    {
        for (int j = i + 1; j < dots.size(); ++j)
            parallels.push_back((float)(dots[j][1] - dots[i][1]) / (float)(dots[j][0] - dots[i][0]));
    }
    for (int i = 0; i < parallels.size() - 1; ++i)
    {
        for (int j = i + 1; j < parallels.size(); ++j)
        {
            if (std::numeric_limits<float>::epsilon() > fabs(parallels[i] - parallels[j]))
                return 1;
        }
    }
    return 0;
}

void main()
{
    solution({ {1,4},{9,2},{3,8},{11,6} });
}