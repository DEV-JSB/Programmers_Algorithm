#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    for (vector<int>::iterator iter = ingredient.begin() + 3 ; iter != ingredient.end();)
    {
        if (ingredient.size() < 4)
            return answer;
        if ((*iter) == 1 && *(iter - 1) == 3 && *(iter - 2) == 2 && *(iter - 3) == 1)
        {
            iter = iter - 3;
            for (int i = 0; i < 4; ++i)
                iter = ingredient.erase(iter);
            ++answer;
        }
        else
            ++iter;
    }
    return answer;
}

void main()
{
    solution({ 1,2,3,4,5,6 });
}