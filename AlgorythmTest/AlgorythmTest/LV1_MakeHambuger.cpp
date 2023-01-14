#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    int countIdx = 0;
    for (vector<int>::iterator iter = ingredient.begin(); countIdx <= ingredient.size() - 4;)
    {
        if (ingredient.size() < 4)
            return answer;
        if ((*iter) == 1 && *(iter + 1) == 2 && *(iter + 2) == 3 && *(iter + 3) == 1)
        {
            for (int i = 0; i < 4; ++i)
                iter = ingredient.erase(iter);
            ++answer;
            countIdx = 0;
            iter = ingredient.begin();
        }
        else
        {
            ++countIdx;
            ++iter;
        }
    }
    return answer;
}