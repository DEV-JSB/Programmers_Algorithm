#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    for (int i = 0; i < number.size() - 2; ++i)
    {
        for (int j = i + 1; j < number.size() - 1; ++j)
        {
            for (int k = j + 1; k < number.size(); ++k)
            {
                answer += number[i] + number[j] + number[k] == 0 ? 1 : 0;
            }
        }
    }
    return answer;
}
void main()
{
    solution({ -2,3,0,2,-5 });
}