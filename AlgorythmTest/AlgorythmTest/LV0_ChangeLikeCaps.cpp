#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    string answer = "";
    for (char c : str)
        answer += ('a' <= c && c <= 'z') ? toupper(c) : tolower(c);
    cout << answer;
    return 0;
}