#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int height) {
    int answer = 0;
    for (int tall : array)
    {
        if (height < tall)
            ++answer;
    }
    return answer;
}