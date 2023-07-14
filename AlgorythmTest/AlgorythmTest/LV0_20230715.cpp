#include <string>
#include <vector>
#include <math.h>
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

int AddSpecificSum(int a, int d, vector<bool> included) {
    int answer = 0;
    int num = a;
    for (int i = 0; i < included.size(); ++i)
    {
        if (included[i])
            answer += num;
        num += d;
    }
    return answer;
}

int GetSameCount(const int a, const int b, const int c)
{
    int sameCount = 0;
    if (a == b)
        ++sameCount;
    if (b == c)
        ++sameCount;
    if (a == c)
        ++sameCount;
    return sameCount;
}
int solution(int a, int b, int c) {
    int answer = 0;
    int sameCount = GetSameCount(a, b, c);
    if (3 == sameCount)
    {
        answer = (a + b + c) * (pow(a, 2) + pow(b, 2) + pow(c, 2)) * (pow(a, 3) + pow(b, 3) + pow(c, 3));
    }
    else if (0 != sameCount)
    {
        answer = (a + b + c) * (pow(a, 2) + pow(b, 2) + pow(c, 2));
    }
    else
        answer = a + b + c;
    return answer;
}