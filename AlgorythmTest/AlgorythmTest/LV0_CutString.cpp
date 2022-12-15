#include <string>
#include <vector>
#include<iostream>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    for (int i = 0; i < my_str.length(); i += n)
        answer.push_back(my_str.substr(i, n));
    return answer;
}

void main()
{
    solution("abc1Addfggg4556b", 6);
}