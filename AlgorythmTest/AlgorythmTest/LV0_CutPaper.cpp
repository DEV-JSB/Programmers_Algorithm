#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    // 0번째와 1번째 그리고 1번째와 2번째의 차가 등차 인지 등비인지 구별한다.
    int BetweenCorrection1 = common[1] - common[0];
    int BetweenCorrection2 = common[2] - common[1];

    return BetweenCorrection1 == BetweenCorrection2 
        ? common[common.size() - 1] + BetweenCorrection1 : common[common.size() - 1] * common[1] / common[0];
}