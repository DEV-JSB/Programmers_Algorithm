#include <string>
#include <vector>

using namespace std;

int TheFirstNegativeNumber(vector<int> num_list) {
    for (int i = 0; i < num_list.size(); ++i)
    {
        if (num_list[i] < 0)
            return i;
    }
    return -1;
}

vector<int> AddElementsArray(vector<int> arr) {
    vector<int> answer;

    for (int num : arr)
    {
        for (int i = 0; i < num; ++i)
        {
            answer.insert(answer.end(), arr[i], arr[i]);
        }
    }

    return answer;
}