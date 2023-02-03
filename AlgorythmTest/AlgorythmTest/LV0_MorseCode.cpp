#include <string>
#include <vector>
#include<map>
using namespace std;

string solution(string letter) {
    string answer = "";
    int startIndex = 0;
    map<string, string> morse{ {".-","a"},{"-...","b"},{"-.-.","c"},{"-..","d"}, {".","e"},{"..-.","f"},
        {"--.","g"},{"....","h"},{"..","i"},{".---","j"},{"-.-","k"},{".-..","l"},{"--","m"},{"-.","n"},{"---","o"},{".--.","p"},{"--.-","q"},{".-.","r"},
        {"...","s"},{"-","t"},{"..-","u"},{"...-","v"},{".--","w"},{"-..-","x"},{"-.--","y"},{"--..","z"}};
    for (int i = 0; i < letter.size() + 1; ++i)
    {
        if (letter[i] == ' ' || letter[i] == '\0')
        {
            answer += morse[letter.substr(startIndex, i - startIndex)];
            startIndex = i + 1;
        }
    }

    return answer;
}

void main()
{
    solution(".... . .-.. .-.. ---");
}