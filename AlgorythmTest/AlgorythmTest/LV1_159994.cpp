#include <string>
#include <vector>
#include <queue>
using namespace std;

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