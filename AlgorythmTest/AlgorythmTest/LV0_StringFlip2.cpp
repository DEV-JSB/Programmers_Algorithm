#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int s, int e) {
    string answer = "";
    answer = my_string;
    int translateCount;
    translateCount = (e - s) / 2;
    for (int i = 0 ; i <= translateCount ; ++i)
    {
        swap(answer[e - i], answer[s + i]);
    }

    return answer;
}