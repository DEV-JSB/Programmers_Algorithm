#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    for (char c : myString)
    {
        answer += ('A' <= c && c <= 'Z') ? tolower(c) : c;
    }
    return answer;
}