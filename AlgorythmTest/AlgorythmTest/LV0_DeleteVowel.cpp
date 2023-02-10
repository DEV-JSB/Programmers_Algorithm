#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for (char ch : my_string)
    {
        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u')
            answer += ch;
    }

    return answer;
}