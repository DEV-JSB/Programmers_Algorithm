#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    for (int num : array)
    {
        answer += num == n ? 1 : 0;
    }
    return answer;
}