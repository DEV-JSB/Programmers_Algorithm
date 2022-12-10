#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    // 0��°�� 1��° �׸��� 1��°�� 2��°�� ���� ���� ���� ������� �����Ѵ�.
    int BetweenCorrection1 = common[1] - common[0];
    int BetweenCorrection2 = common[2] - common[1];

    return BetweenCorrection1 == BetweenCorrection2 
        ? common[common.size() - 1] + BetweenCorrection1 : common[common.size() - 1] * common[1] / common[0];
}