#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    if (numbers.size() == 2)
        return numbers[0] * numbers[1];
    int bigNumIndex1 = 0;
    int bigNumIndex2 = 0;
    int tmpNum = 0;

    for (int i = 0; i < numbers.size(); ++i)
        bigNumIndex1 = numbers[bigNumIndex1] < numbers[i] ? i : bigNumIndex1;
  
    for (int i = 0; i < numbers.size(); ++i)
    {
        if(i == bigNumIndex1)
            continue;
        if (tmpNum < numbers[i])
        {
            tmpNum = numbers[i];
            bigNumIndex2 = i;
        }
    }
    return numbers[bigNumIndex1] * numbers[bigNumIndex2];
}