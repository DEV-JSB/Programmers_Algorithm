#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int tmp = 0 + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9;
    for (size_t i = 0; i < numbers.size();++i)
    {
        tmp -= numbers[i];
    }

    return tmp;
}