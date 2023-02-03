#include <string>
#include <vector>
#include<map>   
using namespace std;


string solution(string X, string Y) {
    string answer = "";
    map<char, int> XcharCount;
    map<char, int> YcharCount;
    for (int i = 0; i < X.length(); ++i)
    {
        if (XcharCount.find(X[i]) == XcharCount.end())
            XcharCount.insert({ X[i],1 });
        else
            XcharCount[X[i]]++;
    }
    for (int i = 0; i < Y.length(); ++i)
    {
        if (YcharCount.find(Y[i]) == YcharCount.end())
            YcharCount.insert({ Y[i],1 });
        else
            YcharCount[Y[i]]++;
    }
    
    if (XcharCount.empty() || YcharCount.empty())
        return "-1";
    else
    {
        for (char c = "9"; "0" <= c; --c)
        {
            if (XcharCount.find(c) != XcharCount.end() && YcharCount.find(c) != YcharCount.end())
            {
                int smallCount = XcharCount[c] < YcharCount[c] ? XcharCount[c] : YcharCount[c];
                for (int i = 0; i < smallCount; ++i)
                    answer += c;
            }
        }
    }
    if (answer == "")
        return "-1";
    bool IsNull = true;
    for (int i = 0; i < answer.length(); ++i)
    {
        if (answer[i] != "0")
        {
            IsNull = false;
            break;
        }
    }

    return IsNull ? "0" : answer;
}

void main()
{
    solution("100", "203045");
}