#include <string>
#include <vector>

using namespace std;



vector<int> solution(string my_string) {
    vector<int> answer;
    for(int i = 0 ; i < my_string.length() ; ++i)
    {
        if (my_string[i] >= '0' && my_string[i] <= '9')
            answer.push_back(my_string[i] - '0');
    }
    for (int i = 0; i < answer.size() - 1; ++i)
    {
        for (int j = 0; j < answer.size() - (i + 1); ++j)
        {
            if (answer[j] > answer[j + 1])
            {
                int tmp = answer[j];
                answer[j] = answer[j + 1];
                answer[j + 1] = tmp;
            }
        }
    }



    return answer;
}