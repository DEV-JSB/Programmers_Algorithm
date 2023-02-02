#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string tmp = "";
    string answer = "";
    while (age)
    {
        tmp += (age % 10) + 'a';
        age /= 10;
    }
    for (int i = tmp.length() - 1 ; i >= 0; --i)
    {
        answer += tmp[i];
    }

    return answer;
}