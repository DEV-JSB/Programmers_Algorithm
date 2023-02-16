#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    if (numbers.size() == 2)
        return numbers[0] * numbers[1];
    int BigBigIndex = 0;
    int BigIndex = 0;
    int MinMinIndex = 0;
    int MinIndex = 0;

    int BigNum = -10001;
    int SmallNum = 10001;
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (SmallNum > numbers[i])
        {
            MinMinIndex = i;
            SmallNum = numbers[i];
        }
        if (BigNum < numbers[i])
        {
            BigBigIndex = i;
            BigNum = numbers[i];
        }
    }
    BigNum = -10001;
    SmallNum = 10001;
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (i == MinMinIndex || i == BigBigIndex)
            continue;
        if (SmallNum > numbers[i])
        {
            MinIndex = i;
            SmallNum = numbers[i];
        }
        if (BigNum < numbers[i])
        {
            BigIndex = i;
            BigNum = numbers[i];
        }
    }

    return numbers[BigBigIndex] * numbers[BigIndex] > numbers[MinMinIndex] * numbers[MinIndex]
        ? numbers[BigBigIndex] * numbers[BigIndex] : numbers[MinMinIndex] * numbers[MinIndex];
}