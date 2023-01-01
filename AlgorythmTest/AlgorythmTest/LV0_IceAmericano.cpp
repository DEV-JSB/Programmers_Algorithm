#include <string>
#include <vector>

using namespace std;

#define AMERICANO_PRICE 5500
vector<int> solution(int money) {
    vector<int> answer;
    answer.push_back(money / AMERICANO_PRICE);
    answer.push_back(money % AMERICANO_PRICE);

    return answer;
}