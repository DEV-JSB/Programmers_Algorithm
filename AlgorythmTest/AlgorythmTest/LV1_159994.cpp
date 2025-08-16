#include <string>
#include <vector>
#include <queue>
using namespace std;
string solution2(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
    queue<string> c1,c2,g;

    for (const string& str : cards1)
    {
        c1.push(str);
    }
    for (const string& str : cards2)
    {
        c2.push(str);
    }
    for (const string& str : goal)
    {
        g.push(str);
    }

    while (!g.empty())
    {
        if (!c1.empty() && c1.front() == g.front())
        {
            c1.pop();
            g.pop();
        }
        else if (!c2.empty() && c2.front() == g.front())
        {
            c2.pop();
            g.pop();
        }
        else
        {
            break;
        }
    }

    return g.empty() ? "Yes" : "No";
}

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) 
{
    string answer = "Yes";

    queue<string> queCard1;
    queue<string> queCard2;
    
    for (string str : cards1)
    {
        queCard1.push(str);
    }
    for (string str : cards2)
    {
        queCard2.push(str);
    }

    int goalIndex = 0;
    while (goalIndex < goal.size())
    {
        if (!queCard1.empty() && queCard1.front() == goal[goalIndex])
        {
            queCard1.pop();
        }
        else if (!queCard2.empty() && queCard2.front() == goal[goalIndex])
        {
            queCard2.pop();
        }
        else
        {
            return "No";
        }
        ++goalIndex;
    }
    return answer;
}