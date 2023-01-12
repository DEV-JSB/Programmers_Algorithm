#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    int countIndex = 0;

        for (vector<int>::iterator iter = ingredient.begin();  countIndex <= ingredient.size() - 4; ++iter, ++countIndex)
        {
            if (ingredient.size() < 4)
                return answer;
            if ((*iter) == 1 && *(iter + 1) == 2 && *(iter + 2) == 3 && *(iter + 3) == 1)
            {
                for (int i = 0; i < 4; ++i)
                    iter = ingredient.erase(iter);
                ++answer;
                iter = ingredient.begin();
                countIndex = 0;
            }
        }
    return answer;
}

void main()
{
    solution({ 2, 1, 1, 2, 3, 1, 2, 3, 1 });
}