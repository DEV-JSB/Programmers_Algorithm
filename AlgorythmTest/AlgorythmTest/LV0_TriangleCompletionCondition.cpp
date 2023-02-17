#include <string>
#include <vector>

using namespace std;

#define CAN 1
#define CANT 2

int solution(vector<int> sides) {
    int bigIndex = 0;
    int exceptBigIndexSum = 0;
    for (int i = 1; i < 3; ++i)
    {
        if (sides[bigIndex] < sides[i])
            bigIndex = i;
    }
    for (int i = 0; i < 3; ++i)
    {
        if (i == bigIndex)
            continue;
        exceptBigIndexSum += sides[i];
    }
    return sides[bigIndex] < exceptBigIndexSum ? CAN : CANT;
}