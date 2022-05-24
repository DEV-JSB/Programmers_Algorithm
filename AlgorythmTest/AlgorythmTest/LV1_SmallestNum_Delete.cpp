#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int smallest = arr[0];
    // 만약 size 가 1일 경우
    if (arr.size() == 1)
    {
        answer.push_back(-1);
        return answer;
    }
    for (int i = 1; i < arr.size(); ++i)
    {
        if (smallest > arr[i])
            smallest = arr[i];
    }
    for (int i = 0; i < arr.size(); ++i)
    {
        if (smallest == arr[i])
            continue;
        answer.push_back(arr[i]);
    }
    return answer;
}
