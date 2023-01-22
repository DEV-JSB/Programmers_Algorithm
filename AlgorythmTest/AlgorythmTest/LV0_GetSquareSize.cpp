#include <string>
#include <vector>

using namespace std;


int solution(vector<vector<int>> dots) {
    int LB_Index = 0;
    int RT_Index = 0;
    for (int i = 1; i < 4; ++i)
    {
        if (dots[LB_Index][0] >= dots[i][0]
            && dots[LB_Index][1] >= dots[i][1])
            LB_Index = i;
        if (dots[RT_Index][0] <= dots[i][0]
            && dots[RT_Index][1] <= dots[i][1])
            RT_Index = i;
    }

    return (dots[RT_Index][0] - dots[LB_Index][0])
        * (dots[RT_Index][1] - dots[LB_Index][1]);
}

