#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = 0;
    // 2 씩 증감한다, idex 를 , 
    // 2 씩 증감하는데 , numbers 의 index 를 넘어서면 0 번째 부터 다시 증감해야 한다.
    // 
    // 반대로 말하면 k 번째로 공을 던지는 사람 -> k - 1 번째에 공을 받은 사람이다.

    // 즉 k - 1 만큼 index 를 2 증감시키면 될듯.
    
    // 2번 던진다- > 1번으로 치환, 1 * 2 
    // 해당 곱한 걸 1 과 더함 -> 1 + 2 == 3
    // index 를 넘어설 것 을 계산해 ((k - 1) * 2) / numbers.size()
    
    answer = 1 + (((k - 1) * 2) % numbers.size());
    return answer;
}