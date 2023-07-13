#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = "";
    int startIdx = s;

    for (char c : overwrite_string)
    {
        my_string[startIdx] = c;
        ++startIdx;
    }
    answer = my_string;
    return answer;
}