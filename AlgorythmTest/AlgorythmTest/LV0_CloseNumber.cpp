#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
    int absoluteValue{ 100 };
    int answer{ 0 };
    int tmp{ 0 };
    for (int i{0}; i < array.size(); ++i)
    {
        tmp = n - array[i] < 0 ? (n - array[i])  * -1 : n - array[i];
        if (tmp < absoluteValue)
        {
            answer = array[i];
            absoluteValue = tmp;
        }
        else if (tmp == absoluteValue)
        {
            answer = answer < array[i] ? answer : array[i];
        }
    }
    return answer;
}