#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = "";
    int index = s;

    for (char c : overwrite_string)
    {
        my_string[index] = c;
        ++index;
    }
    answer = my_string;
    return answer;
}