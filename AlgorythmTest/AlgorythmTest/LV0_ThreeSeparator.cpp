#include <string>
#include <vector>

using namespace std;

vector<string> solution(string myStr)
{
    vector<string> answer;
    string str = "";
    for (char word : myStr)
    {
        if ('a' == word || 'b' == word || 'c' == word)
        {
            if(str != "")
                answer.push_back(str);
            str = "";
        }
        else
            str += word;
    }
    if (str != "")
        answer.push_back(str);
    else if (0 == answer.size())
        answer.push_back("EMPTY");
    return answer;
}