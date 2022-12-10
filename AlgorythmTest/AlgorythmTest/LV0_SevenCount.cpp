#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    int tmp = 0;
    for (int i = 0; i < array.size(); ++i)
    {
        while (array[i])
        {
            tmp = array[i] % 10;
            if (tmp == 7)
                ++answer;
            array[i] /= 10;
        }
    }
    return answer;
}