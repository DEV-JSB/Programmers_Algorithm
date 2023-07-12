#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int s, int e) {
    string answer = "";
    answer = my_string;
    int translateCount;
    translateCount = (e - s) / 2;
    for (int i = 0,start = s , end = e;
        i <= translateCount
        ; ++i , ++start,--end)
    {
        char tmp = answer[end];
        answer[end] = answer[start];
        answer[start] = tmp;
    }

    return answer;
}