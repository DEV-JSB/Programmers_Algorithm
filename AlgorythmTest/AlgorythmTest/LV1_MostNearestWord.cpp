#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> wordIdx;

    for (int i = 0; i < s.length(); ++i)
    {
        if (wordIdx.end() == wordIdx.find(s[i]))
        {
            answer.push_back(-1);
            wordIdx.insert({ s[i],i });
        }
        else
        {
            answer.push_back(i - wordIdx[s[i]]);
            wordIdx[s[i]] = i;
        }
    }
    return answer;
}
void main()
{
    solution("banana");
}