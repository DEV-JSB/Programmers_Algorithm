#include <string>
#include <vector>

using namespace std;
#define JANGGUN 5
#define BYUNGJUNG 3
#define WORK 1
int solution(int hp) {
    int answer = 0;
    answer += hp / JANGGUN;
    hp %= JANGGUN;
    answer += hp / BYUNGJUNG;
    hp %= BYUNGJUNG;
    answer += hp / WORK;
    return answer;
}