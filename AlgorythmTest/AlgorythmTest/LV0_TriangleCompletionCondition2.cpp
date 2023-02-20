#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    int bigIndex{ sides[0] < sides[1] ? 1 : 0 };
    int minIndex{ bigIndex == 1 ? 0 : 1 };

    for (int i = 1; i <= sides[bigIndex]; ++i)
    {
        if (i + sides[minIndex] > sides[bigIndex])
            ++answer;
    }
    for (int i = sides[bigIndex] + 1 ; sides[minIndex] + sides[bigIndex] > i; ++i)
    {
        ++answer;
    }
    return answer;
}