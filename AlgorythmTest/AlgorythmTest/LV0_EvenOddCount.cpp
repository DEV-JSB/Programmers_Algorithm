#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    int oddCount = 0;
    int evenCount = 0;
    for (int num : num_list)
        num % 2 == 0 ? ++evenCount : ++oddCount;
    answer.push_back(evenCount);
    answer.push_back(oddCount);
    return answer;
}