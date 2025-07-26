#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;



vector<int> solution(int N, vector<int> stages) 
{
    vector<int> answer;

    vector<int> remains(N + 1, 0);

    vector<int> reached(N + 3, 0);
    vector<double> failRatio(N + 1);
    vector<int> ret(N);

    for (int challengStage : stages)
    {
        ++remains[challengStage];
    }

    for (int i{ N + 1 };i > 0;--i)
    {
        reached[i] = reached[i + 1] + remains[i];
    }
    for (int i{ N + 1 }; i > 0; --i)
    {
        failRatio[i] = ((reached[i] == 0) ? 0 : 1.0 * remains[i] / reached[i]);
    }

    for (int i{ 1 }; i <= N; ++i)
    {
        ret[i - 1] = i;
    }

    sort(ret.begin(), ret.end(), [&failRatio](int& lhs, int& rhs) {
        if (failRatio[lhs] == failRatio[rhs]) return lhs < rhs;
        return failRatio[lhs] > failRatio[rhs];
        });

    return ret;
}