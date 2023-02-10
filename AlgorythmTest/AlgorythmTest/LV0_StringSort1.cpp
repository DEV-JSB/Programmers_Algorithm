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
    return answer;
}