#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = 0;
    // 2 �� �����Ѵ�, idex �� , 
    // 2 �� �����ϴµ� , numbers �� index �� �Ѿ�� 0 ��° ���� �ٽ� �����ؾ� �Ѵ�.
    // 
    // �ݴ�� ���ϸ� k ��°�� ���� ������ ��� -> k - 1 ��°�� ���� ���� ����̴�.

    // �� k - 1 ��ŭ index �� 2 ������Ű�� �ɵ�.
    
    // 2�� ������- > 1������ ġȯ, 1 * 2 
    // �ش� ���� �� 1 �� ���� -> 1 + 2 == 3
    // index �� �Ѿ �� �� ����� ((k - 1) * 2) / numbers.size()
    
    answer = 1 + (((k - 1) * 2) % numbers.size());
    return answer;
}