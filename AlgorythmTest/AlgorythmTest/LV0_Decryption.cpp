#include <string>
#include <vector>

using namespace std;

string solution(string cipher, int code) {
    string answer = "";
    int multiple = code;
    for (int i = code; i <= cipher.length(); i += multiple)
    {
        answer += cipher[i-1];
    }
    

    return answer;
}