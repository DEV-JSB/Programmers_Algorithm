#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    // 1. total / num == 시작 중점이 되는 듯 하다.
    // 2. total / num 이 짝수인가 ? 
    // 3. 홀수라면 total / num - num.size() / 2 부터 num 횟수 까지 넣으면 되고 
    // 짝수라면 total / num - num.size()/2 - 1 부터 num 횟수 까지 넣으면 된다.
    

    int startPoint = total / num;
    if (num % 2 == 0)
        startPoint -= num / 2 - 1;
    else
        startPoint -= num / 2;
    for (int i = 0; i < num; ++i, ++startPoint)
        answer.push_back(startPoint);
    return answer;
}
