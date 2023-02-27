#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int apearCount[26]{};
    for (char c : s)
        ++apearCount[c - 'a'];
    
    for (int i = 0; i < 26; ++i)
    {
        if (apearCount[i] == 1)
            answer.push_back('a' + i);
    }

    return answer;
}