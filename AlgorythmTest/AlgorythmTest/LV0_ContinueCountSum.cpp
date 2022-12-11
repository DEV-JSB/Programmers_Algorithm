#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    // 1. total / num == ���� ������ �Ǵ� �� �ϴ�.
    // 2. total / num �� ¦���ΰ� ? 
    // 3. Ȧ����� total / num - num.size() / 2 ���� num Ƚ�� ���� ������ �ǰ� 
    // ¦����� total / num - num.size()/2 - 1 ���� num Ƚ�� ���� ������ �ȴ�.
    

    int startPoint = total / num;
    if (num % 2 == 0)
        startPoint -= num / 2 - 1;
    else
        startPoint -= num / 2;
    for (int i = 0; i < num; ++i, ++startPoint)
        answer.push_back(startPoint);
    return answer;
}
