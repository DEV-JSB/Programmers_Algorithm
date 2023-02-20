#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int biggestIndex = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        biggestIndex = arr[i] > arr[biggestIndex] ? i : biggestIndex;
    }
    answer.push_back(arr[biggestIndex]);
    answer.push_back(biggestIndex);
    return answer;
}